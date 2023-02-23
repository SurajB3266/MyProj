###########################################################################################################
#                                                                                                         #
#                          ******Python Script to parse DBC file *******                                  #
#                                                                                                         #
#                                      RealThingks India                                                  #
#                                                                                                         #
###########################################################################################################
#_____________Releases______________________________________________________________________________________
# Updates : 
# Release: 2.0  
# Author: Neeraj Ghate 
# Date: 03/02/2023  
# Feature added - init value, tx and rx mapping excel sheets.
# Note: If you want to check the code,you may print and check necessary variables or objects.
#___________________________________________________________________________________________________________





################################################ IMPORTS ##################################################
import re
import pandas as pd
import sys
import os
###########################################################################################################


#The Debug function is used to execute all print statements together.
# Keep return to False if you do not wish to view the print statements.
# Change the return to True to view all the print statements 
def debug():
    return False

def file_path(path_to_dbc_file):
    
    ############################################### PATH ######################################################
    #---------------------Read DBC as text-----------
    #please enter your device file path here(dont forget to replace all '\' with a '/' in the path)
    #you may change the "sheet_name" parameter according to your input excel file sheet names.

    # main_input=sys.argv[1]
    # main_input=main_input.replace('/','\\')
    dbc_to_text = open(path_to_dbc_file,'rt').read()
    # "C:\Users\NeerajGhate\Desktop\RAFT\DBCParser\Databases\FasSysCan_P1_V2.3_Dbg (1).dbc"
    ###########################################################################################################





    ############################################# REGULAR EXPRESSONS #########################################
    #This block of code extracts the message and signal name line from the above dbc file and stores it inside a list of tuple. [(Data)]
    #Example: [('80 FAA_100HZ_FLT_PWR_FL: 4 FAA_FL\n SG_ Faa_Sts_Pwr48_Fl_Qfr_Na : 30|2@0+ (1,0) [0|2] "N/A"  ASMC\n SG_ Faa_100Hz_Flt_Pwr_Fl_AlvCtr : 7|4@0+ (1,0) [0|14] "N/A"  ASMC)]
    message =re.findall(r'\BO_ ([\S\s]*?)()\n\n\n', dbc_to_text,re.MULTILINE)
    if debug() ==True:
        print(message) 
        print('\n\n')

    cycle_time= re.findall(r'\BA_ "GenMsgCycleTime"([\S\s]*?)();', dbc_to_text,re.MULTILINE)
    if debug() ==True:
        print(cycle_time)
        print('\n\n')
    init_value= re.findall(r'\BA_ "GenSigStartValue" SG_ ([\S\s]*?)();', dbc_to_text,re.MULTILINE)
    if debug() ==True:
        print(init_value)
        print('\n\n')
    ###########################################################################################################





    ################################ CREATING LIST OF LIST FROM LIST OF TUPLES ################################
    # This block of code converts list of tuples [(Data)] to list of lists [[Data]] and filters it for blank elements
    # Example: BEFORE :  [(' BO_ 80 10', ''), (' BO_ 81 10', ''), (' BO_ 82 10', ''), (' BO_ 83 10', ''), (' BO_ 768 40', ''), (' BO_ 256 10', '')]
    #           AFTER : [[' BO_ 80 10'], [' BO_ 81 10'], [' BO_ 82 10'], [' BO_ 83 10'], [' BO_ 768 40'], [' BO_ 256 10']]
    message_list =[list(x) for x in message]
    if debug() ==True:
        print(message_list)
        print('\n\n')
    cycle_list =[list(x) for x in cycle_time]
    if debug() ==True:
        print(cycle_list)
        print('\n\n')
    cycle_list_filtered=[[s for s in sub_list if s] for sub_list in cycle_list]
    if debug() ==True:
        print(cycle_list_filtered)
        print('\n\n')
    init_list =[list(x) for x in init_value]
    if debug() ==True:
        print(init_list)
        print('\n\n')
    init_list_filtered=[[s for s in sub_list if s] for sub_list in init_list]
    if debug() ==True:
        print(init_list_filtered)
        print('\n\n')
    ###########################################################################################################





    ################################## REMOVING THE UNWANTED PREFIXES OF ABOVE LISTS ##########################
    #This code block removes the unnecessary prefixes and stores the above list of lists into a new list
    # Example: BEFORE : [[' BO_ 80 10'], [' BO_ 81 10'], [' BO_ 82 10'], [' BO_ 83 10'], [' BO_ 768 40'], [' BO_ 256 10']]
    #           AFTER : ['80 10', '81 10', '82 10', '83 10', '768 40', '256 10']
    messages_stored=[]
    for i in message_list:
        m_name = [item.split('\n\nBO_') for item in i]
        messages_stored.append(m_name[0])
    if debug() ==True:
        print(messages_stored)
        print('\n\n')
    cycle_time_stored=[]
    for i in cycle_list_filtered:
        m_name = [item.split(' BO_ ') for item in i]
        s=[[s for s in sub_list if s] for sub_list in m_name]
        cycle_time_stored.append(s[0][0])
    if debug() ==True:
        print(cycle_time_stored)
        print('\n\n')
    init_value_stored=[]
    for i in init_list_filtered:
        m_name = [item.split(' SG_ ') for item in i]
        s=[[s for s in sub_list if s] for sub_list in m_name]
        init_value_stored.append(s[0][0])
    if debug() ==True:
        print(init_value_stored)
        print('\n\n')
    ###########################################################################################################





    #################################### SPLITTING ELEMENTS ON BLANKS ##########################################
    #This block of code splits the above code into seperate list elements and stores that in a new list.
    # Example: BEFORE : ['80 10', '81 10', '82 10', '83 10', '768 40', '256 10']
    #           AFTER : ['80,10', '81,10', '82,10', '83,10', '768,40', '256,10']

    x = [item.split('\n SG_ ') for item in messages_stored[0]]
    if debug() ==True:
        print(x)
        print('\n\n')
    y = [item.split(' ') for item in init_value_stored]
    if debug() ==True:
        print(y)
        print('\n\n')

    #Further, it stores the split elements into a dictionary so that the message name and its paramerter is linked together.
    #Example: {'Faa_Gain_Re_ZlFil_Na': '32', 'Faa_Wi_Re_ZlFil_Na': '32', 'Faa_Frq_Re_ZlFil_Ce_Hz': '40', 'Faa_Mofr_Re_ZlGain_Na': '8', 'Faa_Gain_Fn_ZlFil_Na': '32'}
    fin = {words[0]:words[1:] for words in x}
    if debug() ==True:
        print(fin)
        print('\n\n')
    dictionary = {words[1]:words[2] for words in y}
    if debug() ==True:
        print(dictionary)
        print('\n\n')
    #line of code below checks if the key valu pair of dictionary is empty,and if returns true, discards the pair. This clears out unnecessary peice of code.
    fina = {k: v for k, v in fin.items() if v}
    if debug() ==True:
        print(fina)
        print('\n\n')
    #Assigning a list of keys and values of the above dictionary fina.
    key= list(fina.keys())
    value= list(fina.values())
    ###########################################################################################################





    ############################## APPENDING THE ABOVE LIST ELEMENTS TO A NEW LIST #############################
    #elements of above key and value are mapped to each other and iterated in a list which 
    # ensures the order of the elements and their subsequent value is correct. 
    # the for loop is in the length of key, i.e. message elements, and value , i.e, signal elements.

    #Example : ['80 FAA_100HZ_FLT_PWR_FL: 4 FAA_FL', 'Faa_Sts_Pwr48_Fl_Qfr_Na : 30|2@0+ (1,0) [0|2] "N/A"  ASMC', 
    #           '80 FAA_100HZ_FLT_PWR_FL: 4 FAA_FL', 'Faa_Pwr_UBus48_Fl_Watt : 8|10@0- (4,0) [-2048|2044] "W"  ASMC']
    #in above example, you can see that message and its signal are mapped one by one with each other 
    first_list=[]
    for i in range(len(key)):
        for j in range(len(value[i])):
            first_list.append(key[i])
            first_list.append(value[i][j])
    if debug() ==True:
        print(first_list)
        print('\n\n')
    ###########################################################################################################





    ############################## DIVIDING MESSAGE AND SIGNAL MAPPING INTO GROUPS ############################
    #Dividing the message and signal into list of lists
    # Example: BEFORE : [['80 FAA_100HZ_FLT_PWR_FL: 4 FAA_FL', 'Faa_Sts_Pwr48_Fl_Qfr_Na : 30|2@0+ (1,0) [0|2] "N/A"  ASMC', '80 FAA_100HZ_FLT_PWR_FL: 4 FAA_FL', 'Faa_Pwr_UBus48_Fl_Watt : 8|10@0- (4,0) [-2048|2044] "W"  ASMC']]
    #           AFTER : [['80 FAA_100HZ_FLT_PWR_FL: 4 FAA_FL', 'Faa_Sts_Pwr48_Fl_Qfr_Na : 30|2@0+ (1,0) [0|2] "N/A"  ASMC'],[ '80 FAA_100HZ_FLT_PWR_FL: 4 FAA_FL', 'Faa_Pwr_UBus48_Fl_Watt : 8|10@0- (4,0) [-2048|2044] "W"  ASMC']]
    chunk_size = 2
    list_chunked = [first_list[q:q + chunk_size] for q in range(0, len(first_list), chunk_size)]
    if debug() ==True:
        print(list_chunked)
        print('\n\n')
    ###########################################################################################################





    ########### SPLITTING ITEMS INSIDE LISTS AFTER EVERY SPACE AND MERGING SUBLISTS INTO SINGLE LIST ##########
    #Splitting items in list after every space with dilimeter  as ','
    # Example: BEFORE : [['80 FAA_100HZ_FLT_PWR_FL: 4 FAA_FL', 'Faa_Sts_Pwr48_Fl_Qfr_Na : 30|2@0+ (1,0) [0|2] "N/A"  ASMC'],[ '80 FAA_100HZ_FLT_PWR_FL: 4 FAA_FL', 'Faa_Pwr_UBus48_Fl_Watt : 8|10@0- (4,0) [-2048|2044] "W"  ASMC']]
    #           AFTER : [[['80', 'FAA_100HZ_FLT_PWR_FL:', '4', 'FAA_FL'], ['Faa_Sts_Pwr48_Fl_Qfr_Na', ':', '30|2@0+', '(1,0)', '[0|2]', '"N/A"', '', 'ASMC']]]
    fin=[]
    for i in list_chunked:
        x=[item.split(' ') for item in i]
        fin.append(x)
    if debug() ==True:
        print(fin)
        print('\n\n')

    #merging the sublists back to single list
    # Example: BEFORE : [[['80', 'FAA_100HZ_FLT_PWR_FL:', '4', 'FAA_FL'], ['Faa_Sts_Pwr48_Fl_Qfr_Na', ':', '30|2@0+', '(1,0)', '[0|2]', '"N/A"', '', 'ASMC']]]
    #           AFTER : [['80', 'FAA_100HZ_FLT_PWR_FL:', '4', 'FAA_FL', 'Faa_Sts_Pwr48_Fl_Qfr_Na', ':', '30|2@0+', '(1,0)', '[0|2]', '"N/A"', 'ASMC']]
    datas=[]
    for i in range(len(fin)):
        lst = [x for l in fin[i] for x in l]
        datas.append(lst)
    new_list = [[s for s in sub_list if s] for sub_list in datas]
    if debug() ==True:
        print(new_list)
        print('\n\n')

    #Dictionary with cycle time values
    # Example : {'80': '10', '81': '10', '82': '10', '83': '10', '768': '40', '256': '10', '336': '40', '337': '40', '338': '40', '339': '40', '16': '1'}
    cycle_time_dictionary=dict(map(lambda x: x.split(' '), cycle_time_stored))
    if debug() ==True:
        print(cycle_time_dictionary)
        print('\n\n')
    ###########################################################################################################





    ################################### ADDING LIST VALUES TO PANDAS DATAFRAME ################################
    df = pd.DataFrame(new_list)

    #       0                      1  2       3                            4  5        6       7             8       9                10
    # 0     80  FAA_100HZ_FLT_PWR_FL:  4  FAA_FL      Faa_Sts_Pwr48_Fl_Qfr_Na  :  30|2@0+   (1,0)         [0|2]   "N/A"             ASMC
    # 1     80  FAA_100HZ_FLT_PWR_FL:  4  FAA_FL       Faa_Pwr_UBus48_Fl_Watt  :  8|10@0-   (4,0)  [-2048|2044]     "W"             ASMC
    # 2     80  FAA_100HZ_FLT_PWR_FL:  4  FAA_FL            Faa_Sts_Sst_Fl_Na  :  11|3@0+   (1,0)         [0|5]   "N/A"             ASMC
    # 3     80  FAA_100HZ_FLT_PWR_FL:  4  FAA_FL     Faa_100Hz_Flt_Pwr_Fl_Crc  :   3|8@0+   (1,0)       [0|255]   "N/A"             ASMC
    # 4     80  FAA_100HZ_FLT_PWR_FL:  4  FAA_FL  Faa_100Hz_Flt_Pwr_Fl_AlvCtr  :   7|4@0+   (1,0)        [0|14]   "N/A"             ASMC
    # ..   ...                    ... ..     ...                          ... ..      ...     ...           ...     ...              ...
    # 245  722   FAA_DBG_10Hz_MSG_RL:  3  FAA_RL       Emm_Temp_AtHrm_Rl_DegC  :  15|8@0-  (1,50)     [-50|150]  "degC"  CAN_Data_Logger
    # 246  722   FAA_DBG_10Hz_MSG_RL:  3  FAA_RL       Emm_Temp_AtPcb_Rl_DegC  :   7|8@0-  (1,50)     [-50|150]  "degC"  CAN_Data_Logger
    # 247  723   FAA_DBG_10Hz_MSG_RR:  3  FAA_RR  Emm_Temp_AtCtlr_Est_Rr_DegC  :  23|8@0-  (1,50)     [-50|150]  "degC"  CAN_Data_Logger
    # 248  723   FAA_DBG_10Hz_MSG_RR:  3  FAA_RR       Emm_Temp_AtHrm_Rr_DegC  :  15|8@0-  (1,50)     [-50|150]  "degC"  CAN_Data_Logger
    # 249  723   FAA_DBG_10Hz_MSG_RR:  3  FAA_RR       Emm_Temp_AtPcb_Rr_DegC  :   7|8@0-  (1,50)     [-50|150]  "degC"  CAN_Data_Logger

    #dropping column 5 from above as it is not needed, setting index as the 0th column, 
    # reindexing the values and adding cycle time dictionary values in column named Data
    df.drop([5], axis="columns", inplace=True)
    df = df.set_index(0)
    df = df.reindex(df.index.union(cycle_time_dictionary.keys(), sort=False)).rename_axis(0).reset_index()
    df['Data'] = df[0].map(cycle_time_dictionary)
    df = df.explode('Data')

    #        0                      1  2       3                            4        6       7             8       9               10 Data
    # 0     80  FAA_100HZ_FLT_PWR_FL:  4  FAA_FL      Faa_Sts_Pwr48_Fl_Qfr_Na  30|2@0+   (1,0)         [0|2]   "N/A"             ASMC   10
    # 1     80  FAA_100HZ_FLT_PWR_FL:  4  FAA_FL       Faa_Pwr_UBus48_Fl_Watt  8|10@0-   (4,0)  [-2048|2044]     "W"             ASMC   10
    # 2     80  FAA_100HZ_FLT_PWR_FL:  4  FAA_FL            Faa_Sts_Sst_Fl_Na  11|3@0+   (1,0)         [0|5]   "N/A"             ASMC   10
    # 3     80  FAA_100HZ_FLT_PWR_FL:  4  FAA_FL     Faa_100Hz_Flt_Pwr_Fl_Crc   3|8@0+   (1,0)       [0|255]   "N/A"             ASMC   10
    # 4     80  FAA_100HZ_FLT_PWR_FL:  4  FAA_FL  Faa_100Hz_Flt_Pwr_Fl_AlvCtr   7|4@0+   (1,0)        [0|14]   "N/A"             ASMC   10
    # ..   ...                    ... ..     ...                          ...      ...     ...           ...     ...              ...  ...
    # 245  722   FAA_DBG_10Hz_MSG_RL:  3  FAA_RL       Emm_Temp_AtHrm_Rl_DegC  15|8@0-  (1,50)     [-50|150]  "degC"  CAN_Data_Logger  100
    # 246  722   FAA_DBG_10Hz_MSG_RL:  3  FAA_RL       Emm_Temp_AtPcb_Rl_DegC   7|8@0-  (1,50)     [-50|150]  "degC"  CAN_Data_Logger  100
    # 247  723   FAA_DBG_10Hz_MSG_RR:  3  FAA_RR  Emm_Temp_AtCtlr_Est_Rr_DegC  23|8@0-  (1,50)     [-50|150]  "degC"  CAN_Data_Logger  100
    # 248  723   FAA_DBG_10Hz_MSG_RR:  3  FAA_RR       Emm_Temp_AtHrm_Rr_DegC  15|8@0-  (1,50)     [-50|150]  "degC"  CAN_Data_Logger  100
    # 249  723   FAA_DBG_10Hz_MSG_RR:  3  FAA_RR       Emm_Temp_AtPcb_Rr_DegC   7|8@0-  (1,50)     [-50|150]  "degC"  CAN_Data_Logger  100


    #using lambda functions to split the above columns 6,7 and 8 into individual columns,  and convert the + and - signs to signed and unsigned
    df[['Startbit', 'Length [Bit]']] = df[6].apply(lambda x: pd.Series(str(x).split("|")))
    df[['Length [Bit]', 'left']] = df["Length [Bit]"].apply(lambda x: pd.Series(str(x).split("@")))
    df['Byte Order'] = df['left'].str.slice(0,1)
    df['Value Type'] = df['left'].str.slice(1,2)
    #df.loc is used to diretly make logical comparison and change string values inside the dataframe columns/rows
    df.loc[df['Value Type'] == '+','Value Type'] = "Unsigned"
    df.loc[df['Value Type'] == '-','Value Type'] = "Signed"
    df.loc[df['Byte Order'] == '0','Byte Order'] = "Motorola"
    df.loc[df['Byte Order'] == '1','Byte Order'] = "Intel"
    splitData = df[7].str.split(",", n=1, expand=True)
    df['Factor'] = splitData[0].str.strip("()")
    df['Offset'] = splitData[1].str.strip("()")
    df['Msg'] = df[1].str.slice(0,-1)

    #using lambda functions to split min, max values into seperate columns
    df[['Min', 'Max']] = df[8].apply(lambda x: pd.Series(str(x).split("|")))
    df[['waste1', 'Minimum1']] = df["Min"].apply(lambda x: pd.Series(str(x).split("[")))
    df[['Maximum1', 'waste2']] = df["Max"].apply(lambda x: pd.Series(str(x).split("]")))
    #changing the data type from string to float for mathematical opertions
    df['Minimum'] = df['Minimum1'].astype(float)
    df['Maximum'] = df['Maximum1'].astype(float)
    # Merging two columns to create the mid value for min mid max testing
    df['Middle'] = abs((df['Minimum'] + df['Maximum']) //2)

    # dropping unnecessary columns with redundant or incorrect information
    df.drop([1,6,7,8,'left','waste1','waste2','Min','Max','Minimum1','Maximum1'],axis="columns", inplace=True)
    df.drop(["Startbit"],axis="columns",inplace=True)
    #renaming the column index names to required names
    df = df.rename(columns={0:"Can_Id",2:"DLC [Byte]",3:"TX",4:"Signal_Name",9:"Unit",10:"RX",12:"Direction","Data":"Cycle_Time","Msg":"Message_Name"})

    #     Can_Id DLC [Byte]      TX                  Signal_Name    Unit               RX Cycle_Time Length [Bit] Byte Order Value Type Factor Offset          Message_Name  Minimum  Maximum  Middle
    # 0       80          4  FAA_FL      Faa_Sts_Pwr48_Fl_Qfr_Na   "N/A"             ASMC         10            2   Motorola   Unsigned      1      0  FAA_100HZ_FLT_PWR_FL      0.0      2.0     1.0
    # 1       80          4  FAA_FL       Faa_Pwr_UBus48_Fl_Watt     "W"             ASMC         10           10   Motorola     Signed      4      0  FAA_100HZ_FLT_PWR_FL  -2048.0   2044.0     2.0
    # 2       80          4  FAA_FL            Faa_Sts_Sst_Fl_Na   "N/A"             ASMC         10            3   Motorola   Unsigned      1      0  FAA_100HZ_FLT_PWR_FL      0.0      5.0     2.0
    # 3       80          4  FAA_FL     Faa_100Hz_Flt_Pwr_Fl_Crc   "N/A"             ASMC         10            8   Motorola   Unsigned      1      0  FAA_100HZ_FLT_PWR_FL      0.0    255.0   127.0
    # 4       80          4  FAA_FL  Faa_100Hz_Flt_Pwr_Fl_AlvCtr   "N/A"             ASMC         10            4   Motorola   Unsigned      1      0  FAA_100HZ_FLT_PWR_FL      0.0     14.0     7.0
    # ..     ...        ...     ...                          ...     ...              ...        ...          ...        ...        ...    ...    ...                   ...      ...      ...     ...
    # 245    722          3  FAA_RL       Emm_Temp_AtHrm_Rl_DegC  "degC"  CAN_Data_Logger        100            8   Motorola     Signed      1     50   FAA_DBG_10Hz_MSG_RL    -50.0    150.0    50.0
    # 246    722          3  FAA_RL       Emm_Temp_AtPcb_Rl_DegC  "degC"  CAN_Data_Logger        100            8   Motorola     Signed      1     50   FAA_DBG_10Hz_MSG_RL    -50.0    150.0    50.0
    # 247    723          3  FAA_RR  Emm_Temp_AtCtlr_Est_Rr_DegC  "degC"  CAN_Data_Logger        100            8   Motorola     Signed      1     50   FAA_DBG_10Hz_MSG_RR    -50.0    150.0    50.0
    # 248    723          3  FAA_RR       Emm_Temp_AtHrm_Rr_DegC  "degC"  CAN_Data_Logger        100            8   Motorola     Signed      1     50   FAA_DBG_10Hz_MSG_RR    -50.0    150.0    50.0
    # 249    723          3  FAA_RR       Emm_Temp_AtPcb_Rr_DegC  "degC"  CAN_Data_Logger        100            8   Motorola     Signed      1     50   FAA_DBG_10Hz_MSG_RR    -50.0    150.0    50.0

    
    # Final dataframe with columns rearranged as per requirement.
    dfa=df.reindex(columns=['Message_Name','Signal_Name','Can_Id','Value Type','Byte Order','DLC [Byte]','Length [Bit]','TX','RX','Minimum','Middle','Maximum','Factor','Offset','Unit','Cycle_Time'])
    dfa.rename( columns={0:"signal_No"}, inplace=True)
    # Ading caculation for init value and dropping redundant columns
    dfa['Raw_Init'] = dfa['Signal_Name'].map(dictionary)
    dfa['Raw_Init'] = pd.to_numeric(dfa['Raw_Init'])
    dfa['Factor'] = pd.to_numeric(dfa['Factor'])
    dfa['Offset'] = pd.to_numeric(dfa['Offset'])
    dfa['Init Value'] =((dfa['Raw_Init']*dfa['Factor']) +dfa['Offset'])
    dfa.drop(['Raw_Init'],axis='columns',inplace=True)
    
    dfa.fillna(0, inplace=True)


    #              Message_Name                  Signal_Name Can_Id Value Type Byte Order DLC [Byte] Length [Bit]      TX               RX  Minimum  Middle  Maximum  Factor  Offset    Unit Cycle_Time  Init Value
    # 0    FAA_100HZ_FLT_PWR_FL      Faa_Sts_Pwr48_Fl_Qfr_Na     80   Unsigned   Motorola          4            2  FAA_FL             ASMC      0.0     1.0      2.0     1.0     0.0   "N/A"         10         0.0
    # 1    FAA_100HZ_FLT_PWR_FL       Faa_Pwr_UBus48_Fl_Watt     80     Signed   Motorola          4           10  FAA_FL             ASMC  -2048.0     2.0   2044.0     4.0     0.0     "W"         10         0.0
    # 2    FAA_100HZ_FLT_PWR_FL            Faa_Sts_Sst_Fl_Na     80   Unsigned   Motorola          4            3  FAA_FL             ASMC      0.0     2.0      5.0     1.0     0.0   "N/A"         10         0.0
    # 3    FAA_100HZ_FLT_PWR_FL     Faa_100Hz_Flt_Pwr_Fl_Crc     80   Unsigned   Motorola          4            8  FAA_FL             ASMC      0.0   127.0    255.0     1.0     0.0   "N/A"         10         0.0
    # 4    FAA_100HZ_FLT_PWR_FL  Faa_100Hz_Flt_Pwr_Fl_AlvCtr     80   Unsigned   Motorola          4            4  FAA_FL             ASMC      0.0     7.0     14.0     1.0     0.0   "N/A"         10         0.0
    # ..                    ...                          ...    ...        ...        ...        ...          ...     ...              ...      ...     ...      ...     ...     ...     ...        ...         ...
    # 245   FAA_DBG_10Hz_MSG_RL       Emm_Temp_AtHrm_Rl_DegC    722     Signed   Motorola          3            8  FAA_RL  CAN_Data_Logger    -50.0    50.0    150.0     1.0    50.0  "degC"        100         0.0
    # 246   FAA_DBG_10Hz_MSG_RL       Emm_Temp_AtPcb_Rl_DegC    722     Signed   Motorola          3            8  FAA_RL  CAN_Data_Logger    -50.0    50.0    150.0     1.0    50.0  "degC"        100         0.0
    # 247   FAA_DBG_10Hz_MSG_RR  Emm_Temp_AtCtlr_Est_Rr_DegC    723     Signed   Motorola          3            8  FAA_RR  CAN_Data_Logger    -50.0    50.0    150.0     1.0    50.0  "degC"        100         0.0
    # 248   FAA_DBG_10Hz_MSG_RR       Emm_Temp_AtHrm_Rr_DegC    723     Signed   Motorola          3            8  FAA_RR  CAN_Data_Logger    -50.0    50.0    150.0     1.0    50.0  "degC"        100         0.0
    # 249   FAA_DBG_10Hz_MSG_RR       Emm_Temp_AtPcb_Rr_DegC    723     Signed   Motorola          3            8  FAA_RR  CAN_Data_Logger    -50.0    50.0    150.0     1.0    50.0  "degC"        100         0.0

    # print(dfa)

    #printing variant names and giving a choice to print tx and rx excel sheets for the given variant 
    variant_names=list(set(df['TX']))
    if debug==True:
        print(variant_names)
    ###########################################################################################################


    cwd = os.getcwd()
    cwd = str(cwd).replace("/","\\")



    ####################################### SAVE OUTPUT FILE ###################################################
    # Converting the above dataframe into an excel file. Path and name of the excel file can be set below.
    
    dfa.to_excel(f'{cwd}\\internal\\excelfiles\\data3.xlsx',index=False)
    ###########################################################################################################
    
    return variant_names

