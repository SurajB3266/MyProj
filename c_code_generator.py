###########################################################################################################
#                                                                                                         #
#                             ******Pyhton code to generate C code******                                      #
#                                                                                                         #
#                                      RealThingks India                                                  #
#                                                                                                         #
###########################################################################################################
#_________________________________Releases_________________________________________________________________
# Update : 
# 04/01/2023  : Aditya kale  - C code generation for Test suite 0,1,2 
#10/02/2023 : Aditya kale - 
# -Modified c code (Macro decelration)
# -Integrate the generate c code with RAFT_SWC.c 
# -created a .h file for all declared macros which are generated for the python script.
#                                                     
# Note: If you want to check the code,you may print and check necessary variables or objects.
#__________________________________________________________________________________________________________

#---------------------------------------------------------------------------------------------------------#
#                                            DISCRIPTION                                                  #
#---------------------------------------------------------------------------------------------------------#
#Pyhton script to generate c code base on the XL input

#---------------------------------------------------------------------------------------------------------#
#                                             Import libraries                                            #
#---------------------------------------------------------------------------------------------------------#
import pandas as pd
import os
# import rte_generator  #rte generate is the file which will short the rte calls from the main .c file 
import Merge_code  #Merge code file will 
import sys


global cwd
cwd = os.getcwd()
cwd = str(cwd).replace('/','\\')

def CcodeGenerator(variant):
    #-------------------------------------------------------------------------------------------------------- #
    #                                                Debug code                                               #
    #---------------------------------------------------------------------------------------------------------#

    #The Debug function is used to execute all print statements together.
    # Keep return to False if you do not wish to view the print statements.
    # Change the return to True to view all the print statements 
    def debug():  # prints(list0,list1,list2)
        return False

    def debug1():  # print the RTE API list and data type
        return False
    #-------------------------------------------------------------------------------------------------------- #
    #                                                Decleration                                              #
    #---------------------------------------------------------------------------------------------------------#
    #Empty list are use to store the Rte api and the data type in a single element.
    RTE_list = []
    RTE_list1= []
    RTE_list2=[]
    ##Empty list are use to store the Rte api and the data type in 0 and 1 elements
    splitylist0 = []
    splitylist1 = []
    splitylist2 = []
    #Empty strings are use to store the c code and append the code into a file -rte_text.c
    macro_case=""
    first_case = ""
    second_case= ""
    third_case=""
    fourth_case=""
    fifth_case=""
    define_case=""
    #---------------------------------------------------------------------------------------------------------#
    #                                       Path to the File                                                  #
    #---------------------------------------------------------------------------------------------------------#
    #For more file related info refer README.txt
    inputFile = f"{cwd}\\internal\\Rte\\RTE_file.txt" #RTE APi and data type file which is generated through rte_generator.py
    c_code = f"{cwd}\\internal\\Rte\\rte_test.c" #This is main c code with all the test cases and the test suits
    macro = f"{cwd}\\output\\Ccode\\RAFT_SWC.h"  #File contains all the macros for the test case and test suit

    #To run the c_code_generator.py from the command line
    #<c_code_generator path>pyhton3 ./c_code_generator.py <path/TSTC.xlsx>
    # main_input=sys.argv[1]
    main_input = f"{cwd}\\internal\\excelfiles\\TSTC_{variant}.xlsx"
    # main_input= "C:/1PROJECT_WORK/RAFT/final checkin/TSTC (2).xlsx"
    #list0
    XL_Test_suit_0= pd.read_excel(main_input)
    list0=XL_Test_suit_0.values.tolist()  ## convert xl shett into list0
    if debug() ==True:
        print(list0) 
        print('\n\n')
    #list1   
    XL_Test_suit_1 = pd.read_excel(main_input,sheet_name='Test_Suite_1')
    list1=XL_Test_suit_1.values.tolist()  ## convert xl shett into list1
    if debug() ==True:
        print(list1) 
        print('\n\n')
    #list2
    XL_Test_suit_2 = pd.read_excel(main_input,sheet_name='Test_Suite_2')
    list2=XL_Test_suit_2.values.tolist()  ## convert xl shett into list2
    if debug() ==True:
        print(list2) 
        print('\n\n')
    #---------------------------------------------------------------------------------------------------------#
    #                                  Delete the existing files .h and .c file                               #
    #---------------------------------------------------------------------------------------------------------#
    #Delete the files if exist rte_test.c and RAFT_SWC.h
    if os.path.exists(c_code):
        os.remove(c_code)
        if debug() ==True:
            print(f"{c_code} .c updated with test suit and test cases.")
            print('\n\n')
    if os.path.exists(macro):
        os.remove(macro)
        if debug() ==True:
            print(f"{macro} .h file updated.")
            print('\n\n')
    #---------------------------------------------------------------------------------------------------------#
    #              Creating the list of RTE API and Data type by parsing the RTE_file.txt
    #---------------------------------------------------------------------------------------------------------#
    # Example: Before :Asmc_1000Hz_F_Cmd_AlvCtr Rte_IRead_RAFT_SWC_Main_RAFT_R_Asmc_1000Hz_F_Cmd_AlvCtr_Asmc_1000Hz_F_Cmd_AlvCtr(void),
    #                   Ascc_St_Req_Na Rte_IRead_RAFT_SWC_Main_RAFT_R_Ascc_St_Req_Na_Ascc_St_Req_Na(void)
    #           After:[['Ascc_St_Req_Na', 'Rte_IRead_RAFT_SWC_Main_RAFT_R_Ascc_St_Req_Na_Ascc_St_Req_Na()'], 
    #                   ['Asmc_1000Hz_F_Cmd_AlvCtr', 'Rte_IRead_RAFT_SWC_Main_RAFT_R_Asmc_1000Hz_F_Cmd_AlvCtr_Asmc_1000Hz_F_Cmd_AlvCtr()'],
    #                  

    #---------------------------------------------------------------------------------------------------------#
    #Find the list0 elemets in the RTE file(RTE_file.txt) and if found store it in RTE_list
    with open(inputFile, 'r') as filedata:
    # Traverse in each line of the file 
            for line in filedata:
                for g in range(len(list0)):
                    givenString = list0[g][3]
                # Checking whether the given string is found in the line data
                    if givenString in line:
                        # Print the line, if the given string is found in the current line
                        b=line.replace("*  ","")
                        c=b.replace("(void)","()") # Remove the void and replace it with ()
                        RTE_list.append(c)
    filedata.close() 

    #Find the list1 elemets in the RTE file(RTE_file.txt) and if found store it in RTE_list1
    with open(inputFile, 'r') as filedata:      
            for line1 in filedata:
                for g1 in range(len(list1)):
                    givenString1 = list1[g1][2]
                # Checking whether the given string is found in the line data
                    if givenString1 in line1:
                        # Print the line, if the given string is found in the current line
                        b1=line1.replace("*  ","")
                        c1=b1.replace("(void)","()") # Remove the void and replace it with ()
                        RTE_list1.append(c1)
    filedata.close()
    
    #Find the list2 elemets in the RTE file(RTE_file.txt) and if found store it in RTE_list2
    with open(inputFile, 'r') as filedata: 
            for line2 in filedata:
                for g2 in range(len(list2)):
                    givenString2 = list2[g2][2]
                # Checking whether the given string is found in the line data
                    if givenString2 in line2:
                        # Print the line, if the given string is found in the current line
                        b2=line2.replace("*  ","")
                        c2=b2.replace("(void)","()")
                        RTE_list2.append(c2)
                        
    #Split the list in 0,1 elements form a single element(RTE_list,RTE_list1.RTE_list2) and stored in splitylist0,splitylist1,splitylist2
    for split in RTE_list:
        splited = split.split()
        splitylist0.append(splited)
    if debug1() ==True:
        print(splitylist0) 
        print('\n\n')
    for split1 in RTE_list1:
        splited1 = split1.split()
        splitylist1.append(splited1)
    if debug1() ==True:
        print(splitylist1) 
        print('\n\n')
    for split2 in RTE_list2:
        splited2 = split2.split()
        splitylist2.append(splited2)
    if debug1() ==True:
        print(splitylist2) 
        print('\n\n')
    filedata.close()
    #---------------------------------------------------------------------------------------------------------#
    #                                       Writing the c code                                                #
    #---------------------------------------------------------------------------------------------------------#
    #This is the c code which will get stored in RAFT_SWC.h and rte_test.c file
    ## Using %s string concatenation to insert values into a string.
    # The %s placeholder is used to represent a string value that will be inserted into the final string.

    #Define the macros and which will get stored into the RAFT_SWC.h file
    CODEGEN_MACRO_TC='''
    #define TestCase_%s %su'''

    #Macros defined for the testsuits 0,1,2
    CODEGEN_MACRO_TS='''
    #define Suite_0 0u
    #define Suite_1 1u
    #define Suite_2 2u
    '''
    #Stabdarc definations
    CODEGEN_INIT='''

        uint8 retval_u8 = E_NOT_OK;
        uint8 RAFT_Resp_Result_u8[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};  
    '''
    #Assign data type(%s) to the signal name (%_sig) is the signal name 
    CODEGEN_DECALARE='''
        %s %s_sig;
    '''
    CODEGEN_INMAIN='''
            /*Read the RAFT Test request signal*/
            /*RAFT Req. Signal format
            * Byte 0: Test Suite Number
            * Byte 1: Test Case Number
            * Byte 2 to n: Test value needed for the test*/
        switch (Data[0])
        {
    '''
    #Generate the testsuit 0,1,2 based on the input provided
    CODEGEN = '''
            case Suite_%s: 
                switch (Data[1])
                { 
    '''
    #Generate the testcase  based on the input provided
    CODEGEN1 = '''
                    case TestCase_%s: 
                        %s_sig = %s;
                        if (%s_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[%s] = Suite_%s;
                            RAFT_Resp_Result_u8[%s] = TestCase_%s;
                            RAFT_Resp_Result_u8[%s] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[%s] = Suite_%s;
                            RAFT_Resp_Result_u8[%s] = TestCase_%s;
                            RAFT_Resp_Result_u8[%s] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    '''
    CODEGEN3='''
                }
            break; 
    '''
    CODEGEN2='''           
        }
    '''
    #---------------------------------------------------------------------------------------------------------#
    #                                       generating the .c file from workspace                             #
    #---------------------------------------------------------------------------------------------------------#
    f=p=z=a=i=array_index=0  #Incremtal variables 
    # Using %s string concatenation to insert elements from a list into a string.
    # The %s placeholder is used to represent a string value that will be inserted into the final string.
    # In this case, the elements from the list are being inserted into the string using the %s placeholder.

    #macros Test cases and store it in RAFT_SWC.h file -       #define TestCase_0 0u
    for l in range(len(list0)) :
        f = open(macro, "a+")
        macro_case=CODEGEN_MACRO_TC%(list0[l][1],list0[l][1]) #   Append the macros Test cases into .h file
        f.write(macro_case)
        f.close()

    #macros Test test suit 0,1,2    - #define Suite_0 0u
    f = open(macro, "a+")
    f.write(CODEGEN_MACRO_TS)
    f.close() 

    #standard Deceleration     
    f = open(c_code, "a+")
    f.write(CODEGEN_INIT)
    f.close() 

    #Declare the signals names 
    #eg: Ascc_St_Req_Na Ascc_St_Req_Na_sig;
    #    Asmc_1000Hz_F_Cmd_AlvCtr Asmc_25Hz_Sts_AlvCtr_sig;

    # In this case, the elements from the list1 and splitylist1 are being inserted into the string using the %s placeholder.
    for Third in range(len(list1)) :
        f = open(c_code, "a+")
        define_case=CODEGEN_DECALARE%(splitylist1[Third][0],list1[Third][2]) 
        f.write(define_case)
        f.close()
        
    # standard deceleration --CODEGEN_INMAIN
    f = open(c_code, "a+")
    f.write(CODEGEN_INMAIN)
    f.close() 

    # Test suits
    f = open(c_code, "a+")
    second_case = CODEGEN%(list0[0][0])
    f.write(second_case)
    f.close()

    #Generate code for Test Suit 0
    ## In this case, the elements from the list0 and splitylist0 are being inserted into the string using the %s placeholder.
    for line in list0 :
        f = open(c_code, "a+")
        i+=1
        if i != 1: #increment the array index from zero -RAFT_Resp_Result_u8[0] 
            #Before: Initiating the array index by 0,1,2
            #RAFT_Resp_Result_u8[0] = Suite_0;
            #RAFT_Resp_Result_u8[1] = TestCase_0;
            #RAFT_Resp_Result_u8[2] = E_NOT_OK;  
            array_index += 3 
            #Increment the array index by 3 from 0 to 3,6,9,12,15.....
            # RAFT_Resp_Result_u8[231] = Suite_0;
            # RAFT_Resp_Result_u8[232] = TestCase_77;
            # RAFT_Resp_Result_u8[233] = RTE_E_OK;;
        first_case = CODEGEN1%(list0[i-1][1],list0[i-1][3],splitylist0[i-1][1],list0[i-1][3],array_index,list0[i-1][0],array_index+1,list0[i-1][1],array_index+2,array_index,list0[i-1][0],array_index+1,list0[i-1][1],array_index+2)
        f.write(first_case)
        f.close()
    f = open(c_code, "a+")  
    f.write(CODEGEN3)
    third_case = CODEGEN%(list1[0][0])
    f.write(third_case)
    f.close()  

    #Generate code for Test Suit 1
    ## In this case, the elements from the list1 and splitylist1 are being inserted into the string using the %s placeholder.
    for line in list1: 
        f = open(c_code, "a+")
        #Increment the array index from the previous value again by 3 
        array_index += 3
        # RAFT_Resp_Result_u8[234] = Suite_1;
        # RAFT_Resp_Result_u8[235] = TestCase_0;
        # RAFT_Resp_Result_u8[236] = RTE_E_OK;
        a+=1   
        fifth_case = CODEGEN1%(list1[a-1][1],list1[a-1][2],splitylist1[a-1][1],list1[a-1][2],array_index,list1[a-1][0],array_index+1,list1[a-1][1],array_index+2,array_index,list1[a-1][0],array_index+1,list1[a-1][1],array_index+2)
        f.write(fifth_case)
        f.close()
    f = open(c_code, "a+")   
    fourth_case=CODEGEN%(list2[0][0])
    f.write(CODEGEN3)
    f.write(fourth_case)
    f.close()

    #Generate code for Test Suit 2
    ## In this case, the elements from the list2 and splitylist2 are being inserted into the string using the %s placeholder.
    for line in list2: #
        f = open(c_code, "a+")
        z+=1
        #Increment the array index from the previous value again by 3 
        array_index += 3
        # RAFT_Resp_Result_u8[237] = Suite_2;
        # RAFT_Resp_Result_u8[238] = TestCase_0;
        # RAFT_Resp_Result_u8[239] = RTE_E_OK;
        sixth_case = CODEGEN1%(list2[z-1][1],list2[z-1][2],splitylist2[z-1][1],list2[z-1][2],array_index,list2[z-1][0],array_index+1,list2[z-1][1],array_index+2,array_index,list2[z-1][0],array_index+1,list2[z-1][1],array_index+2)
        f.write(sixth_case)
        f.close()
    f = open(c_code, "a+")
    f.write(CODEGEN3)
    f.write(CODEGEN2)
    f.close()  #Close the files