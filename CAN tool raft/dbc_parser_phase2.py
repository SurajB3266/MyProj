###########################################################################################################
#                                                                                                         #
#                          ******Python Script to create variant excel *******                            #
#                                                                                                         #
#                                      RealThingks India                                                  #
#                                                                                                         #
###########################################################################################################

#_____________Releases______________________________________________________________________________________
# Updates : 
# Release: 1.0  
# Author: Neeraj Ghate 
# Date: 06/02/2023  
# Feature added - Initial setup
# Note: If you want to check the code,you may print and check necessary variables or objects.
#___________________________________________________________________________________________________________

################################################ IMPORTS ##################################################
import pandas as pd
import sys
import os
###########################################################################################################

global cwd
cwd= os.getcwd()
print(cwd)
cwd= str(cwd).replace("/","\\")


def option_selected(value):
    
    ############################################### Read Exel sheet ###########################################
    dfa=pd.read_excel(f'{str(cwd)}\\internal\\excelfiles\\data3.xlsx',index_col=[0])
    dfa = dfa.loc[:, ~dfa.columns.str.contains('^Unnamed')]
        
    ###########################################################################################################
    # print(dfa) 
    #################################### Creaing excel sheet from input value #################################
    # value=sys.argv[1]
    df_tx=dfa[dfa['TX'].str.contains(f"{value}")]
    df_rx=dfa[dfa['RX'].str.contains(f"{value}")]
    
    ############################################################################################################
    # df_rx
    ####################################### SAVE OUTPUT FILE ###################################################
    # Converting the above dataframe into an excel files. Path and name of the excel files can be set below.
    
    df_tx.to_excel(f"{cwd}\\internal\\excelfiles\\tx_list_{value}.xlsx")
    df_rx.to_excel(f"{cwd}\\internal\\excelfiles\\rx_list_{value}.xlsx")
    ############################################################################################################
    
def variant_cyclic_signals(value):
    ############################################### Read Exel sheet ###########################################
    dfa1=pd.read_excel(f"{cwd}\\internal\\excelfiles\\all_{value}.xlsx",index_col=[0])
    dfa1 = dfa1.loc[:, ~dfa1.columns.str.contains('^Unnamed')]    
  
    #################################### Creaing excel sheet from input value #################################
    new_dfa = dfa1[dfa1['Cycle_Time'] !=0]
    # print(new_dfa)
    new_dfa.to_excel(f"{cwd}\\internal\\excelfiles\\all_cyclic_{value}.xlsx")
    # print(df_Cycle_time)
    