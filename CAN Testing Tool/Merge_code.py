
#---------------------------------------------------------------------------------------------------------#
#                                            DISCRIPTION                                                  #
#---------------------------------------------------------------------------------------------------------#
#Python code to merge the RAFT_SWC and rte_test code  ---#For files info refer the README.txt
#-------------------------------------------------------------------------------------------------------- #
#                                              imports                                           #
#---------------------------------------------------------------------------------------------------------#
import os


global c_file_path
global cwd

cwd = os.getcwd()
cwd = str(cwd).replace("/","\\")


def MergecfileandDEfines(path):
    # c_file_path="RAFT_SWC.c"
    c_file_path =path
    text_file_path=f"{cwd}\\internal\\Rte\\rte_test.c"
    #Function name isnide which the code need to be merged
    function_name="FUNC(Std_ReturnType, RAFT_SWC_CODE) DataServices_RAFT_TestDataIndetifier_WriteData(P2CONST(uint8, AUTOMATIC, RTE_RAFT_SWC_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RAFT_SWC_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */"


    #Function to integrate the both RAFT_SWC.c and rte_test.c
    def add_text_file_above_return_statement_in_function(c_file_path, text_file_path, function_name):
        with open(c_file_path, 'r') as c_file, open(text_file_path, 'r') as text_file:
            c_file_lines = c_file.readlines()
            text_file_contents = text_file.read()

            in_function = False
            for i, line in enumerate(c_file_lines):
                if function_name in line: #If the function name is found go inside the function
                    in_function = True 
                if 'return RTE_E_OK' in line and in_function: # Search for teh return RTE_E_OK and paste the generated c code above it
                    c_file_lines = c_file_lines[:i] + [text_file_contents] + c_file_lines[i:]
                    break
                if '}' in line and in_function:
                    break
        
        try:
            with open(f"{cwd}\\output\\Ccode\\RAFT_SWC.c", 'w') as file:
                file.writelines(c_file_lines)
        except:
            os.remove(f"{cwd}\\output\\Rte\\RAFT_SWC.c")
            print("file removed")
            with open(f"{cwd}\\output\\Ccode\\RAFT_SWC.c", 'w') as file:
                file.writelines(c_file_lines)
    add_text_file_above_return_statement_in_function(c_file_path, text_file_path, function_name)

