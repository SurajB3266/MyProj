##############################################################################################################################################################################
#                                                                                                                                                             
#                                                      ******<_CAPL_CODE_GENERATOR_>******                                      
#                                                                                                         
#                                                                 RealThingks India                                                  
#                                                                                                                                          
##############################################################################################################################################################################


#____________________________________________________________________Releases_________________________________________________________________________________________________
#   <version>  <Responsible>  <date>      : Feature Added                                                 
#    v1.1.0     Rushikesh J.  6.02.2023  :1.Common Variable: Create sharing variable between test request and response to track test suite and test case number.
#                                         2.NRC_0x10(GR) handling: If NRC 0x10 is received in the negative response from ECU then mark it as test couldn't be completed.
#                                           as the ecu didn't respond with pass or fail status and it might be because of Ecu Reset or there is a breakpoint in the code 
#                                           or connection is missing.
#                                         3.Status Monitoring Flag: Create a sharing flag between Diag response and request to notify if the current test is completed or not
#                                         4.List of signals to be tested: It take input(IN CAPL CODE) from .csv file and according to that run test suit and test case . 
#                                         5.Result Generation: In CAPL code  we write a  result in log file,can be used to document the test case result.                                        
#_____________________________________________________________________________________________________________________________________________________________________________


#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#                                                                     DISCRIPTION                                                  
# The CAPL generator code required std(as per RAFT_technical ) two  excel file as a input one is main excel file(it will be generated from DBC file or ECU.Extract file-Rx msg)
# and another one will be test suit and test case excel file.        
# By using this input it create .can file as output of script and this .can file used  to check,minimum ,maximum and mid value value of signal(Rx) in CANalyzer.                                                           
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------





#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#                                                                    Import libraries                                             
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

import pandas as pd
import os


global cwd 
cwd = os.getcwd()
cwd = str(cwd).replace('/','\\')

def CaplGenerator(variant,filtetype):
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    # Debug print will be enable if print_flag = 1 
    print_flag = 0

    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #                                                                  This will be take input excel file                           
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    # Read_RxSignals = pd.read_excel("C:\\Users\\SurajBiradar\\Desktop\\RAFT\\Development_RAFT\\IntegrationV0.1\\1_st_release\\internal\\excelfiles\\rx_list_FAA_FL_Final.xlsx")  # Read receive signal excel file 
    # Read_TestCase  = pd.read_excel("C:\\Users\\SurajBiradar\\Desktop\\RAFT\\Development_RAFT\\IntegrationV0.1\\1_st_release\internal\\TSTC_FAA_FL.xlsx",sheet_name="Test_Suite_0")   # Read Test case excel file
    if filtetype == "Rx":
        Read_RxSignals = pd.read_excel(f"{cwd}\\internal\\excelfiles\\rx_list_{variant}.xlsx")
        Read_TestCase = pd.read_excel(f"{cwd}\\internal\\excelfiles\\TSTC_{variant}.xlsx",sheet_name="Test_Suite_0")
        # Read_RxSignals_2 =Read_RxSignals_1.drop['RX'] 
        # Read_RxSignals =Read_RxSignals_2.drop['TX']    
    elif filtetype == "Tx":
        Read_RxSignals = pd.read_excel(f"{cwd}\\internal\\excelfiles\\tx_list_{variant}.xlsx")
        Read_TestCase = pd.read_excel(f"{cwd}\\internal\\excelfiles\\TSTC_{variant}.xlsx",sheet_name="Test_Suite_0")

    Read_RxSignals_list = Read_RxSignals.values.tolist()     # Convert Rx excel to python list
    Read_TestCase_list  = Read_TestCase.values.tolist()      # Convert test case excel to python list




    # Print debug flag is enable 
    if(print_flag == 1):
        # Print rx message list
        print("receive message list ->")
        print(Read_RxSignals_list)
        
        # Print test suite and test case number
        print("test suit and test case list ->")
        print(Read_TestCase_list)

    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # It create a list with required columns:message,signal,min,mid,max,cycle time,init val, factor and offset from above Read_RxSignals                       
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    first_list = []
    for list in Read_RxSignals_list:
        message    = list[0]
        signal     = list[1]
        min        = list[9]
        mid        = list[10]
        max        = int(list[11])
        cycle_time = list[15]
        # init_val   = list[16]
        factor     = list[12]
        offset     = list[13]
        
        first_list.append(message)
        first_list.append(signal)
        first_list.append(min)
        first_list.append(mid)
        first_list.append(max)
        first_list.append(factor)
        first_list.append(offset)
        first_list.append(cycle_time)


    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # We need 8 input parameters. hence, chunk size is marked to 8 bytes and provided in sequential order                  
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    chunk_size   = 8
    list_chunked = [first_list[i:i + chunk_size] for i in range(0, len(first_list), chunk_size)]

    # Print debug flag is enable 
    if(print_flag == 1):
        # Print prepared chunk list in above code
        print("required column list -> chunked_list")
        print(list_chunked)
    

    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # Create 3 types of lists: signal_new_list,cycle_time_new_list and message_new_list from Read_RxSignals_list              
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    # Create signal list
    signal_new_list = [] 
    for list in Read_RxSignals_list:
        signal = list[1]
        signal_new_list.append(signal)
    
    # Create cycle time list
    cycle_time_new_list = [] 
    for list in Read_RxSignals_list:
        cycle_time = list[15]
        cycle_time_new_list.append(cycle_time)
    

    # Create message list
    message_new_list = [] 
    for list in Read_RxSignals_list:
        message = list[0]
        message_new_list.append( message)
    

    # Print debug flag is enable then print all the extracted lists  
    if(print_flag == 1):
        # Print new signal list
        print("signal list ->")
        print(signal_new_list)
        
        # Print new cycle time list 
        print("cycle time list->")
        print(cycle_time_new_list)
        
        # Print new message list
        print(" message list->")
        print(message_new_list)


    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # Map signal to message functionality:                                                                                                                                        
                                        # Before : [msg 1,sig1],[msg 1,sig2]                                                                                                      
                                        # After  : [msg1 ,sig1,sig2]  along with respective message parameters                                                                      
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ 


    # Local variable declaration
    r = 0
    s = 0
    x = 0
    a = 0

    final_message     = []
    cy_time_list      = []
    final_msg_sg_list = []
    size              = len(list_chunked)

    # Buffer size needed 50% of size of all Rx chunk list
    buffer_size = round(size*0.5)                                              
                                        
    # This loop is used to extract signals from respective message
    for i in range(size + buffer_size):                                 
        if(x <= (size - 1)):
            if (list_chunked[r][0] == list_chunked[x][0]):                       
                x = x + 1
            else:
                r = x
                u = signal_new_list[s:r]                  # Extracted signal list is merged in new list
                h = set(cycle_time_new_list[s:r])         # Extracted cycle time is merged in new list
                k = set(message_new_list[s:r])            # Extracted message is merged in new list
                s = r
                final_msg_sg_list.append(u)               # Append extracted signal list on final message signal list
                cy_time_list.append(h)                    # Append extracted cycle time on final cycle time list
                final_message.append(k)                   # Append extracted message on final message list

    r = x            
    u = signal_new_list[s:r]                               
    h = set(cycle_time_new_list[s:r])
    k = set(message_new_list[s:r]) 

    final_msg_sg_list.append(u)                           # Addition of last message in main list because its not coming in else part 
    cy_time_list.append(h)                                 
    final_message.append(k)  

    # Print debug flag is enable 
    if(print_flag == 1 ):
        # Print above created lists
        print("signal list for  different message -> ")
        print(final_msg_sg_list)
        
        print(" cycle time for  different message -> ")
        print(cy_time_list)
        
        print("  message name list -> ")
        print(final_message)


    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # Convert set inside cycle and message list to noraml value in same list:
                                                                            # Before : [{40}, {1}, {10}, {10}, {0}, {0}]
                                                                            # After  : [40, 1, 10, 10, 0, 0]    
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ 


    # For cycle time
    final_cycle_time = [x for [x] in cy_time_list]

    # For message
    final_1_message = [x for [x] in final_message]


    # Print debug flag is enable 
    if(print_flag == 1):
        # Print above created lists
        print(" set to list for cycle time ")
        print(final_cycle_time)
        
        print(" set to list for message  ")
        print(final_1_message)
    
    
    
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    # Remove old file backup and create new CAPL file
    file_to_delete = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can",'w')
    file_to_delete.close()







    #----------------------------------------------------------------------------CAPL_Code_START ----------------------------------------------------------------------------------






    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #                                                                          CAPL FILE DESCRIPTION                                       
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    STRING121 ='''
/**********************************************************************************************************************
*  FILE DESCRIPTION
* -------------------------------------------------------------------------------------------------------------------
*             File       : CAPL_Generator.can
*			       Release    : 1.0  
*             Author     : Rushikesh v. Jadhav
*             Date       : 10/12/2023 
*             Description: This CAPL script is used to check minimum,,medium and maximum values of signal.
*                           and also generate log report as a test result.
*********************************************************************************************************************/

/**************************************************[Include definitions]*********************************************/
'''



    f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")
    f.write(STRING121)
    f.close()

    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #                                                                    Includes and Variable section                                             
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
        
    STRING1='''

/* @!Encoding:1252 */
includes
{


}
    '''

    STRING2 ='''
/**************************************************[Variable definitions]*********************************************/

variables
{

/* Declaration of variable for diagnostics request and response */   
message `UDS_REQ_FAA_FL Request;              /* For Request */ 
message `UDS_RESP_FAA_FL response;            /* For Response */               
    '''

    # Add two strings 
    z = STRING1 + STRING2
    f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")
    f.write(z)
    f.close()


    STRING3 ='''

/* Declaration for Diagnostics request global variable */
int flag         = 1;        /* Initialy it should be -> 1 (Without any response  we need to send 1st request ) */                              
int dealy_flag   = 0; 
int test_suit    = 0;   
int test_case    = 0;
int actual_value = 0;
int size_dlc     = 0x0B;     /* DLC = Service Identifier + Data Identifier + 10 bytes of Data */   
int SID_NO       = 0x2E;     /* Service Identifier */                         
int DID_NO_h     = 0x02;     /* DID number = 0x0200 */    
int DID_NO_f     = 0x00;
    
    '''

    # Add Diagnostics request global variable information
    z = STRING3
    f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")
    f.write(z)
    f.close()


    STRING4='''

/* Declaration variable for csv file */
int len,i,j      = 0 ;    
int values[%s];              /* In this array we store int value of .csv file ( neglecting [by using CAPL code] other string parameter) */ 
char buffer [%s];            /* As a  string  we read .csv file and store in this array */ 
int arrayIndex   = 0;
int temp         = 0;
dword glbHandle;
int arraySize;


/**********************************************************************************************************************
* Read message name and then create a global variable by using prefix( _var) @end: 
* Before :  ASMC_25HZ_ST_REQ_FAA
* After  : ASMC_25HZ_ST_REQ_FAA_var  
**********************************************************************************************************************/

    '''

    # Add global variable information for csv file
    # Int array size take maximum length(i.e test case present in test case excel + buffer for char array size(its length should be 5 *of length int arraySize))
    z = STRING4%(6 *len(Read_TestCase_list), 7 * len(Read_TestCase_list)) 
    f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")                 
    f.write(z)
    f.close()
    
    
    # Add message and Global variables 
    STRING5 ='''
message %s %s_var ;                                                    
'''


    STRING6 ='''int %s_var = 0;'''       


    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # Declaration of  message with its global variable:
                                                    # Before : ASMC_25HZ_ST_REQ_FAA
                                                    # After  : ASMC_25HZ_ST_REQ_FAA_var   
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ 


    z = 0
    # Maximum value for loop = no. of msg present in dbc file.
    for i in range(len(final_1_message)):                              
        z = z+1
        a = STRING5%(final_1_message[z-1],final_1_message[z-1])              # Take a message variable declaration
        f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")
        f.write(a)
        f.close()       
    # Maximum value for loop = no. of signal present in dbc file.
        for s in range(len(final_msg_sg_list[z-1])):                                  
            b = STRING6%(final_msg_sg_list[z-1][s])                          # Take a signal list                                      
            f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")  
            f.write(b + "\n")
            f.close()

        
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # Declaration of cycle timer in variable block
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ 


    STRING71 = '''

/* Timer declaration for cyclic messages and timer Delay variable is configured based on msg cyclic time */  
    '''

    f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")  
    f.write(STRING71)
    f.close() 
        
    STRING7 = '''
msTimer _timer%s;                                     
float timer_delay%s =%s;
    '''   
            
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # Remove the spontaneous signals and create a list for cyclic signals
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ 

    without_zero = []  

    # Remove similar cycle time signals and mapped under existing cycle time to avoid duplication   
    my_list = set(final_cycle_time)  
    my_list = sorted(my_list)

    # Maximum loop variable = no.of msg present in dbc file
    for i in range(len(my_list)):  
    # Check msg cycle time is zero or not  
        if(my_list[i] != 0): 
    # Add cyclic(only) msg to new list
            without_zero.append(my_list[i])  
            

    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # Implementation logic for cyclic signals timer
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ 


    zs = 0   
    # Maximum loop variable = no.of msg present in dbc file         
    for i in range(len(without_zero)): 
        kl = STRING7%(without_zero[i],without_zero[i],without_zero[i]) 
        f  = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")  
        f.write(kl + "\n")
        f.close()


    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # Declaration for timer loop creation(IN CAPL)
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------   
    
    
    STRING8 = '''
/* Declaration  of timer for loop creation */ 
msTimer _timercheck;
int timer_delay = 1;
    '''   

    f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")  
    f.write(STRING8)
    f.close()  
        
    # Added curly bracket at the end of variable block in CAPL
    STRING9 = '''
}
    '''  
        
    f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")  
    f.write(STRING9)
    f.close()

    # This block will be excuted on start event
    STRING10 = '''
on start
{
/* Print statments */   
write(" CAPL FILE READY TO -> -START ");
write(" PRESS -> d  FOR TO RUN TEST CASE AND TEST SUIT ");  


/* Set timer for cyclic message */  
    '''

    f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")  
    f.write(STRING10)
    f.close()

    # This block will load the parameters under start event(set cyclic timer)
    STRING11 ='''setTimer(_timer%s,timer_delay%s); 
    '''

    for i in range(len(without_zero)): 
        kt = STRING11%(without_zero[i],without_zero[i])
        f  = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")
        f.write(kt + "\n")
        f.close()



    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # Parsing of CSV file
    # Convert Char to int Logic :
                                # Before : 1,2,3,4
                                # After  : 1 2 3 4
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------   
    


    STRING12 ='''   

/**********************************************************************************************************************
* CSV file -> Convert char to int value by neglecting unwanted characters: 
* Before :  1,2,3,4,
* After  :  0 1 2 3 4  
**********************************************************************************************************************/

/* Note : Read both the files : .csv & CANalyzer .config file and both should be in same folder */
glbHandle = OpenFileRead ("NEW_file.csv",0);  


/* Check file is found or not */                 
if(glbHandle != 0)
{
    fileGetString(buffer,elcount(buffer),glbHandle);
    /* File found */
    write(" file(CSV) found ");
    arrayIndex = 0;
    temp = 0;
    len  = strlen(buffer);
    for ( i = 0; i < len; i++) 
    {
        if (buffer[i] >= '0' && buffer[i] <= '9') {         /* It take only int values */
        temp = temp * 10 + (buffer[i] - '0');
        }
        else if (buffer[i] == ',') {                        /* Remove ',' */ 
        values[arrayIndex++] = temp;
        temp = 0;
        }
    }
    values[arrayIndex] = temp;                             /* Final Int Array */
        
}
else{
write(" file(CSV) not found");
}
    '''    
    
    f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")  
    f.write(STRING12)
    f.close()  
    
    # Added curly bracket at the end of on start block in CAPL       
    f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+") 
    # String9 contains the end curly bracket 
    f.write(STRING9)                             
    f.close()

    # Add comment for notification of timer(cyclic) event start
    STRING131= '''
/* On timer event implementation to send periodic message on CAN  Bus */
    '''

    f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+") 
    f.write(STRING131)                             
    f.close()


    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # Implementation for add on timer event and also add parameters under that event
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------     
    
            
    STRING13 ='''on timer _timer%s
{
    setTimer(_timer%s,timer_delay%s); 
    '''      

    STRING14 = '''
    %s_var.%s =  %s_var;  
    '''
    STRING15 = '''
    output(%s_var); 
    '''
    STRING16 = '''
}
    '''   

    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # Add msg and cycle time in signal list :
                                            # Before : list1 = [sig1,sig2,sig3,sig4] list2 = [cycle1,cycle2]  list3 = [msg1,msg2] 
                                            # After  : list1= [sig1,sig2,sig3,sig4,msg1,cycle1]
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    # Add respective message to respective signal   
    for i in range(len(final_msg_sg_list)):
        final_msg_sg_list[i].append(final_1_message[i])    
    
    # Add  respective message to  respective cycle time  
    for i in range(len(final_msg_sg_list)):
        final_msg_sg_list[i].append(final_cycle_time[i])   
    
    # Print debug flag is enable 
    if(print_flag == 1):
        print("final_msg_sg_list + message + cycle time")
        print(final_msg_sg_list)


    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # Acc to time delay put messages(load its value and send) in that respective timer
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    # Local variable
    w   = 0
    h   = 0
    sgg = 0

    # Loop rotated up to no. cyclic msg present in dbc file
    for i in range(len(without_zero) ) : 
        w   = w+1
        abb = STRING13%(without_zero[w-1],without_zero[w-1],without_zero[w-1])    # Take a cyclic time 
        f   = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+") 
        f.write(abb)
        f.close()
        h = 0
        for j in range(len( final_msg_sg_list)):                                  # Loop rotated up to the msg(rx-cyclic or and cyclic) present in dbc file
            h = h +1
            if(without_zero[w-1] == final_msg_sg_list[h-1][-1]):                  # Check different msg for same time delay
                sgg = 0
                for s in range(len(final_msg_sg_list[h-1]) - 2):                  # Loop rotes up to the no of signals present in that message.
                    sgg  = sgg +1
                    abbc = STRING14%(final_msg_sg_list[h-1][-2],final_msg_sg_list[h-1][sgg - 1],final_msg_sg_list[h-1][sgg - 1])   # take a signal 
                    f    = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+") 
                    f.write(abbc)
                    f.close() 
                abbcd = STRING15%(final_msg_sg_list[h-1][-2])                       # Take a message  name (to send output on bus)  
                f     = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+") 
                f.write(abbcd)
                f.close()
        f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")
        # Add curly bracket to timer end 
        f.write(STRING16)                                  
        f.close()        

        
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # Create key based trigger in CAPL to run the test suit
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------   
    
        
    STRING17 ='''
/* On key event start */

on key 'd'
{
write(" KEY ->  d IS PRESSED ");  
setTimer(_timercheck,timer_delay);      
}

/* On timer start */
    '''    
    
    # Add On key trigger event in CAPL   
    f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")  
    f.write(STRING17)
    f.close()  
    
    
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #  Add parameter  under on timer( timer which is create a loop ) event
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    
    STRING18 ='''
on timer _timercheck
{

/* Timer is set again to create a loop */    
setTimer(_timercheck,timer_delay);                                      

/* Array end  @99 value, j variable is used for array increment */  
if(values[j] != 99)                                
{
/* Check test suit number */
switch (values[j]) {
    '''  



    # Add set timer 
    f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")  
    f.write(STRING18)
    f.close()  


    
            
    # Increment on test suite change 
    STRING19 ='''
    case(%s) :
        /* Check test case inside the test suit */                                                                                         
        switch(values[j+1]){
        
    '''



    # Increment on test case change 
    STRING20 ='''
            case(%s) :                                                                               
    '''



    # Send request for cyclic message
    STRING21 ='''
                    if(flag == 1)                                                        
                        {  
                            flag = 0;
                                                
                            %s_var = ((%s/%s)-%s); 

                            %s_var.%s =  %s_var;  
                            
                            output(%s_var);                                      
                                            
                                                
                            test_suit    = %s;
                            test_case    = %s;
                            actual_value = ((%s/%s)-%s);
                            
                            write("test suit = %s, test case = %s,",test_suit,test_case); 
                                            
                            Request.dlc = 8;                                                     /* CAN Frame DLC */
                            Request.byte(0) = 0x10;                                              /* FF frame */
                            Request.byte(1) = size_dlc;                                          /* Total length of request message -> DID length + SID + DID  = 0B */ 
                            Request.byte(2) = SID_NO;                                            /* SID = 2E */  
                            Request.byte(3) = DID_NO_h;                                          /* DID Number Byte 1 = 0x00 */                        
                            Request.byte(4) = DID_NO_f;                                          /* DID Number Byte 2 = 0x00 */ 
                            Request.byte(5) =  test_suit;                                        /* Test Suite Number  - B0 */
                            Request.byte(6) =  test_case;                                        /* Test Case Number - B1 */
                            Request.byte(7) =  actual_value;                                     /* Test value needed for the test - Min, Mid, Max - B2 */
                                                
                                            
                            output(Request);                                 
                                                
                        }
                        break;
    '''




    # Send request for  non cyclic message
    STRING22 ='''
                        if(flag == 1)                                                        
                            {  
                                flag   = 0;
                                                    
                                %s_var = ((%s/%s)-%s);                                      
                                
                                output(%s_var);                                               
                                                
                                                    
                                test_suit    = %s;
                                test_case    = %s;
                                actual_value = ((%s/%s)-%s);
                                
                                write("test suit = %s, test case = %s,",test_suit,test_case); 
                                                
                                Request.dlc = 8;                                                    /* CAN Frame DLC */
                                Request.byte(0) = 0x10;                                             /* FF frame */
                                Request.byte(1) = size_dlc;                                         /* Total length of request message -> DID length + SID + DID  = 0B */
                                Request.byte(2) = SID_NO;                                           /* SID = 2E*/  
                                Request.byte(3) = DID_NO_h;                                         /* DID Number Byte 1 = 0x00 */                   
                                Request.byte(4) = DID_NO_f;                                         /* DID Number Byte 2 = 0x00 */ 
                                Request.byte(5) =  test_suit;                                       /* Test Suite Number  - B0 */
                                Request.byte(6) =  test_case;                                       /* Test Case Number - B1 */
                                Request.byte(7) =  actual_value;                                    /* Test value needed for the test - Min, Mid, Max - B2 */
                                                    
                                                
                                output(Request);                                 
                                                    
                            }
                            break;
    '''




    # End curly bracket( after every test suit)
    STRING23 ='''
        }
    '''


    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #  To send diagnostics request under on timer(loop)
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ 
                
    # For write window of CAPL
    list_to_write = ['%d']  
    
    # Local variable  
    z  = 0
    j  = 0 
    rj = 0  
    zs = 0

    # ADD 1st test suite                    
    t1 = STRING19%(Read_TestCase_list[0][0]) 
    f  = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")  
    f.write(t1)
    f.close()  
                    
    size_TSTC = len(Read_TestCase_list) 


    # Buffer size(max size) - considerations for one by one test suit increasing in excel file
    buffer_size_TSTC = size_TSTC *2         
                
    # Loop rotate up to test cases present in each test suite + buffer time       
    for i in range(buffer_size_TSTC):  
        if(rj<=(size_TSTC-1)): 
            # Take only test cases present in each test suite
            if(Read_TestCase_list[z][0] == Read_TestCase_list[rj][0]):  
                # Take a decision of test  suit change
                rj = rj +1
                t1 = STRING20%(Read_TestCase_list[rj-1][1]) 
                f  = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+") 
                f.write(t1)
                f.close()
                # print(Read_RxSignals_list[rj-1][15])
                tc = STRING21%(Read_TestCase_list[rj-1][3],Read_TestCase_list[rj-1][4],Read_TestCase_list[rj-1][6],Read_TestCase_list[rj-1][7],Read_TestCase_list[rj-1][2],
                        Read_TestCase_list[rj-1][3],Read_TestCase_list[rj-1][3],Read_TestCase_list[rj-1][2],Read_TestCase_list[rj-1][0],Read_TestCase_list[rj-1][1],
                        Read_TestCase_list[rj-1][4],Read_TestCase_list[rj-1][6],Read_TestCase_list[rj-1][7],
                        list_to_write[0],list_to_write[0])  # For cyclic msg 
                f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+") 
                f.write(tc)
                f.close()
        # else:
        #     f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")  
        #     f.write(STRING23 )                                                 # Add end curly brackets to test case end
        #     f.close()
        #     z  = rj
        #     t1 = STRING19%(Read_TestCase_list[rj][0])                          # ADD  when test suite change 
        #     f  = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")  
        #     f.write(t1)
        #     f.close()
            
                                                
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # For stop the timer
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------  


    STRING24 ='''
                }
        
} 

}
else
{
write(" test suit E-N-D"); 
writeToLog("test suit E-N-D");
cancelTimer(_timercheck);              /* To stop timer (break loop) -> after Complete all test cases.*/

}

}
    '''


    f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")  
    f.write(STRING24)
    f.close()


    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    # Diagnostics response code
    #------------------------------------------------------------------------------------------------------------------------------------------------------------------------------  



    STRING25='''
/*_______________________________________ Diagnostics resopnse__________________________________________________*/

on message `UDS_RESP_FAA_FL
{ 

write(" Response  Received" );

if(this.byte(0) == 0x30)
{
    
    
    
    Request.dlc = 8;
    Request.byte(0) = 0x21;   
    Request.byte(1) = 0x03;
    Request.byte(2) = 0x04;
    Request.byte(3) = 0x05;                           
    Request.byte(4) = 0x06;
    Request.byte(5) = 0x07;
    Request.byte(6) = 0x00;
    Request.byte(7) = 0x00;
    
    output(Request); 
    write("Complete Request send" );
    
}

else 
{
    write(" complete Request  not send " );
}



/*_______________________________________ Positive__response__________________________________________________*/


if (((this.byte(1) == 0x6E)&&(this.byte(2) == 0x02))&&((this.byte(3) == 0x00)&&(this.byte(0) == 0x3)))
    
{
    flag = 1;        /* Indication for response received */
    j    = j+2;      /* Inc. for next test suit and test case */
    write(" Positive response");
    writeToLog("test suit = %d,test case = %d ,response = Positive",test_suit ,test_case ); /*Write to log file( which is .csv file)*/ 
}



/*_______________________________________ Negative__response__________________________________________________*/


    if (((this.byte(1) == 0x7F)&&(this.byte(2) == 0x2E))&&((this.byte(3) == 0x22)&&(this.byte(0) == 0x3)))
{
    
    
    flag = 1;
    j    = j+2;
    write("  Negative response ");
    writeToLog("test suit = %d,test case = %d ,response = Negative ",test_suit, test_case );
}



/*_______________________________________ Response_other than +ve 0r -ve__________________________________________________*/

    
if (((this.byte(1) == 0x7F)&&(this.byte(2) == 0x2E))&&((this.byte(3) == 0x10)&&(this.byte(0) == 0x3)))
{
    
    
    flag = 1;
    j    = j+2;
    write(" Din't respond with pass or fail status ");
    writeToLog("test suit = %d,test case = %d ,response = test couldn't be completed as the ecu dint respond with pass or fail status",test_suit, test_case );
}



}

    '''


    f = open(f"{cwd}\\output\\capl\\CAN_up_MIN.can", "a+")  
    f.write(STRING25)
    f.close()


    if print_flag:
        print("Done")   


    #--------------------------------------------------------------------------------------E-N-D------------------------------------------------------------------------------------------   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


    
    
            
            

            
    
        
