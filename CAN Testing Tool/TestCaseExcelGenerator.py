###########################################################################################################
#                                                                                                         #
#                        ****** Test Suite Test Case Generator python Script *******                      #
#                                                                                                         #
#                                      RealThingks India                                                  #
#                                                                                                         #
###########################################################################################################
#_____________Releases______________________________________________________________________________________
# Updates : 
# Release: 1.0  
# Author: Neeraj Ghate 
# Date: 02/12/2023  
# Feature added - Initial setup
# Note: If you want to check how the code is working you may print and check necessary variables or objects.
#___________________________________________________________________________________________________________

#_____________________IMPORTS_________________________
import pandas as pd
import xlsxwriter
import os

# for debug make dbu True
global debug
debug =False

global cwd
cwd = os.getcwd()
cwd = cwd.replace('/',"\\")



def CreateTestCase(variant,filtertype):
    #---------------------Read Excel and store it in a dataframe-----------
    #please enter your device file path here(dont forget to replace all '\' with a '/' in the path)
    # ExcelFilePath = f"{cwd}\\internal\\excelfiles\\all_{variant}.xlsx"
    if filtertype == "Rx":
        ExcelFilePath = f"{cwd}\\internal\\excelfiles\\rx_list_{variant}.xlsx"
    elif filtertype == "Tx":
        ExcelFilePath = f"{cwd}\\internal\\excelfiles\\tx_list_{variant}.xlsx"
    df1 = pd.read_excel(ExcelFilePath)
    # Convereting the dataframe to a nested list
    x=df1.values.tolist()

    # Creating empty lists to store/ append specific data
    first_list=[]
    second_list=[]
    third_list=[]

    #-----------for loop for appendinfg values in the above created empty lists----------------
    for list in x:
    # This loop iterates inside the nested list which is obtained form previous excel sheet and stores values into variables.
    # Then, it appends the values to an empty list in required order.

    # assigning a variable to specific list indices. 
    # for All_variant list
        # message=list[1]
        # signal=list[2]
        # min=list[10]
        # mid=list[11]
        # max=int(list[12])
        # cycle_time=list[16]
        # init_val=list[17]
        # factor=list[13]
        # offset=list[14]

        # for RX list
        message=list[0]
        signal=list[1]
        min=list[9]
        mid=list[10]
        max=int(list[11])
        cycle_time=list[15]
        init_val=list[16]
        factor=list[12]
        offset=list[13]

    # Appending the above variables to the empty list in required order.
    #first_list = list of all values for first test suite

        first_list.append(message)
        first_list.append(signal)
        first_list.append(min)
        first_list.append("Min")
        first_list.append(factor)
        first_list.append(offset)
        first_list.append(message)
        first_list.append(signal)
        first_list.append(mid)
        first_list.append("Mid")
        first_list.append(factor)
        first_list.append(offset)
        first_list.append(message)
        first_list.append(signal)
        first_list.append(max)
        first_list.append("Max")
        first_list.append(factor)
        first_list.append(offset)

    #second_list = list of all values for second test suite
        second_list.append(signal)
        second_list.append(cycle_time)

    #third_list = list of all values for third test suite
        third_list.append(signal)
        third_list.append(init_val)


    if debug==True:
        print(first_list)

    #_____________________Breaking lists into required sized nested lists_________________________

    # creating nested lists inside of first_list, second_list and third_list so that the first n values will be for one signal, then second n values for next signal and so on.
    # n here is devided by the chunk size
    chunk_size = 6
    list_chunked = [first_list[i:i + chunk_size] for i in range(0, len(first_list), chunk_size)]

    chunk_size_2 = 2
    list_chunked_2 = [second_list[q:q + chunk_size_2] for q in range(0, len(second_list), chunk_size_2)]

    chunk_size_3 = 2
    list_chunked_3 = [third_list[r:r + chunk_size_2] for r in range(0, len(third_list), chunk_size_3)]


    #_____________________Adding Test Suite and Test Case Numbers to nested lists_________________________
    #Setting up counters for above list_chinked elements so that we can iterate test suite and test case in required list_chunked
    count=0
    for l in list_chunked:
        count+=1
        list_chunked[count-1].insert(0,count-1)
        list_chunked[count-1].insert(0,0)

    counter=-1
    for m in list_chunked_2:
        counter+=1
        list_chunked_2[counter].insert(0,counter)
        list_chunked_2[counter].insert(0,1)

    counters=-1
    for n in list_chunked_3:
        counters+=1
        list_chunked_3[counters].insert(0,counters)
        list_chunked_3[counters].insert(0,2)

    #_____________________Writing list_chukned to excel_________________________

    #creating an excel file
    workbook=xlsxwriter.Workbook(f'{cwd}\\internal\\excelfiles\\TSTC_{variant}.xlsx')

    #creating an excel sheet "Test_Suite_0" inside the excel file
    worksheet = workbook.add_worksheet("Test_Suite_0")
    bold = workbook.add_format({'bold': True})
    worksheet.write('A1', 'Test Suite', bold)
    worksheet.write('B1', 'Test Case', bold)
    worksheet.write('C1', 'Message Name', bold)
    worksheet.write('D1', 'Signal Name', bold)
    worksheet.write('E1', 'Value', bold)
    worksheet.write('F1', 'Mid/Mid/Max', bold)
    worksheet.write('G1', 'Factor', bold)
    worksheet.write('H1', 'Offset', bold)
    # iterating the elements under above name headers
    for row_num, data in enumerate(list_chunked):
        worksheet.write_row(row_num+1, 0, data)

    #creating an excel sheet "Test_Suite_1" inside the excel file
    worksheet = workbook.add_worksheet("Test_Suite_1")
    bold = workbook.add_format({'bold': True})
    worksheet.write('A1', 'Test Suite', bold)
    worksheet.write('B1', 'Test Case', bold)
    worksheet.write('C1', 'Signal Name', bold)
    worksheet.write('D1', 'Cycle_time', bold)
    # iterating the elements under above name headers
    for row_num, data in enumerate(list_chunked_2):
        worksheet.write_row(row_num+1, 0, data)

    #creating an excel sheet "Test_Suite_2" inside the excel file
    worksheet = workbook.add_worksheet("Test_Suite_2")
    bold = workbook.add_format({'bold': True})
    worksheet.write('A1', 'Test Suite', bold)
    worksheet.write('B1', 'Test Case', bold)
    worksheet.write('C1', 'Signal Name', bold)
    worksheet.write('D1', 'Init_Value', bold)
    # iterating the elements under above name headers
    for row_num, data in enumerate(list_chunked_3):
        worksheet.write_row(row_num+1, 0, data)

    #closing the worksheet and excel sheet 
    workbook.close()




