###########################################################################################################
#                                                                                                         #
#                        ****** Report Generator python Script *******                                    #
#                                                                                                         #
#                                      RealThingks India                                                  #
#                                                                                                         #
###########################################################################################################
#_____________Releases_____________________________________________________________________________________
# Updates : 
# Release: 2.0  
# Date: 21/02/2023  
# Feature added - Detailed Report and Overall analysis visualization.
# Note:If you want to check how the code is working you may print and check necessary variables or objects.
#_________________________________________________________________________________________________________#

############################################__DISCRIPTION__################################################
#                                                                                                         #
# This code is responsible for generating test report from input ACSII and test suit test case excel-->   #
# file.---------------------------------------------------------------------------------------------------#
#---------------------------------------------------------------------------------------------------------#

#------------------------------------------__IMPORT_LIBRARIES__-------------------------------------------#
import re
import pandas as pd
import numpy as np
import jinja2
from IPython.display import display, HTML
from flask import Flask, render_template
from matplotlib import pyplot as plt
import sys
import os
from datetime import datetime
################################__VARIABLE TO ENABLE/DISABLE ALL PRINT FUNCTIONS__#########################

print_var = False #-----------Enable all print functions-->True / Disable all print functions-->False
equal_list = []
string_rows = []

global cwd 
cwd = os.getcwd()
cwd = str(cwd).replace('/','\\')

def ReportGen(variant,filterType):
    ###############################################__FUNCTION_DECLARATION__####################################

    def Debug():
        return False

    #--------------FUNCTION FOR BACKGROUND COLOUR OF TEST REPORT RESULT (PASS, FAIL, NOT TESTED)--------------#
    def highlight_color(val):
        if val == 'PASS':
            color = 'limegreen' #-------bg colour limegreen when PASS
        elif val == 'FAIL':
            color = 'red' #-------bg colour red when FAIL
        elif val == 'NOT TESTED':
            color = 'yellow' #-------bg colour yellow when NOT TESTED
        else:
            color = 'white' #-------bg colour white when no PASS, FAIL, NOT TESTED
        return 'background-color: %s' % color

    #---------------------FUNCTION TO CREATE DESCRIPTION FROM SIGNAL, MESSAGE NAME AND TEST TYPES-------------#
    def create_description(row):
        signal_name = row["Signal Name"] #--------take data from input row under column "Signal Name"
        message_name = row["Message Name"] #------take data from input row under column "Message Name"
        type_of_testing = row["Test Type"] #------take data from input row under column "Test Type"
        # Return string representation of description:
        return f"The signal {signal_name} for message {message_name} is tested for {type_of_testing}." 

    #----------------------------------------__CREATING AUTOCPT ARGUMENTS__-----------------------------------#
    def func(pct, allvalues):
        absolute = int(pct / 100.*np.sum(allvalues))
        return "{:.1f}%\n({:d} g)".format(pct, absolute)

    ######################################__GENERATING_PIE_&_BAR_DIAGRAM__#####################################
    #-----This part of code generates TSTC_new.xlsx file and generates pie and bar diagram images->-----------#
    #-----based on generated TSTC_new.xlsx file. These images will be imported in HTML webpage in next->------#
    #-----section of the code.--------------------------------------------------------------------------------#
    #---------------------------------------------------------------------------------------------------------#

    # cwd = os.getcwd() #--------------Get path of current working directory

    if Debug:
        print("Current working Directory: ",cwd) if print_var == True else None #-------To check current working directory
    # fpath = os.path.join(cwd,'Logging.asc') #------------Argument 1: path to Input ASCII file
    # fpath1 = os.path.join(cwd,'test_case.xlsx') #------------Argument 2: path to Input EXCEL file
    # output_excel_path = os.path.join(cwd,'TSTC_new.xlsx') #------------Argument 4: path to OUTPUT EXCEL file
    # output_pie_path = os.path.join(cwd,'Test_Report_pie.png') #------------Argument 5: path to OUTPUT pie diagram
    # output_bar_path = os.path.join(cwd,'Test_Report_bar.png') #------------Argument 6: path to OUTPUT bar diagram
    # input_pie_path = os.path.join(cwd,'Test_Report_pie.png') #-------------Argument 7: path to INPUT pie diagram
    # input_bar_path = os.path.join(cwd,'Test_Report_bar.png') #-------------Argument 7: path to INPUT bar diagram

    output_excel_path = f"{cwd}\\internal\\report\\TSTC_{variant}.xlsx" #------------Argument 4: path to OUTPUT EXCEL file
    path_to_asci_file = f"{cwd}\\internal\\report\\log_{variant}.asc" # path to Input ASCII file
    output_pie_path   = f"{cwd}\\internal\\report\\Test_Report_pie_{variant}.png" #------------Argument 5: path to OUTPUT pie diagram
    output_bar_path   = f"{cwd}\\internal\\report\\Test_Report_bar_{variant}.png"
    # To verify wheather filter is Tx type of Rx type and give path accordingly.
    if filterType == "Rx":
        path_to_testCase = f"{cwd}\\internal\\excelfiles\\TSTC_{variant}.xlsx"
    elif filterType == "Tx":    
        path_to_testCase = f"{cwd}\\internal\\excelfiles\\TSTC_{variant}.xlsx"

    open_capl= open(path_to_asci_file).read() #----------------read ASCII file
    excel_path= path_to_testCase #---------------- assigned variable for TSTC excel file

    # read excel file
    df = pd.read_excel(excel_path)
    # Read Ascii file
    newfile  = re.findall(r"= (\w+)",open_capl,re.MULTILINE)
    chunk_size = 3
    list_chunked = [newfile[i:i + chunk_size] for i in range(0, len(newfile), chunk_size)]

    # Convert DataFrame to list of lists
    rows = [row.tolist() for index, row in df.iterrows()]

    print(list_chunked) if print_var == True else None
    print(rows) if print_var == True else None

    for sublist2 in rows: #-------this loop is to convert data in string for comparing purpose
        string_sublist2 = [str(x) for x in sublist2] #--covert data of any datatype to string
        string_rows.append(string_sublist2) #---append converted string to list
    print(string_rows) if print_var == True else None

    for i in list_chunked:
        for sublist in string_rows:
            if i[0] == sublist[0] and i[1] == sublist[1]:
                if i[2] == "NOT_TESTED": #----if "NOT_TESTED" found in list
                    sublist.append("NOT TESTED") #-----replace it with "NOT TESTED"
                else:
                    sublist.append(i[2]) #------if "NOT_TESTED" not found in list append as it is.
                equal_list.append(sublist)
    print(equal_list) if print_var == True else None

    list_final=[] #-----this is final list after appending all required data from "equal_list" to it.
    for sublist in equal_list:
            list_final.append(sublist[0]) #-----appending Test suit number
            list_final.append(sublist[1]) #-----appending Test case number
            list_final.append(sublist[2]) #-----appending Message name
            list_final.append(sublist[3]) #-----appending Signal name
            list_final.append(sublist[5]) #-----appending Test Type
            list_final.append(sublist[-1]) #-----appending test Result

    print(list_final) if print_var == True else None

    chunk_size_2 = 6
    list_chunked_2 = [list_final[i:i + chunk_size_2] for i in range(0, len(list_final), chunk_size_2)]               
    print(list_chunked_2) if print_var == True else None

    #--------------Generating the new OUTPUT excel file from list_chunked_2------------------------------------#
    df =pd.DataFrame(list_chunked_2,columns=['Test Suite','Test Case', 'Message Name', 'Signal Name','Test Type','Test Result'])
    df.index += 1
    df.to_excel(output_excel_path,index=True,index_label="Sr.No.")

    # Sample DataFrame --> path to excel sheet
    df1 = pd.read_excel(output_excel_path)

    # Add a new column named "New Column"
    df1.insert(loc=df1.columns.get_loc('Test Type') + 1, column='Description',value = None)
    df1["Description"] = df1.apply(create_description, axis=1)
    # Save the updated DataFrame to a new Excel file
    df1.to_excel(output_excel_path)

    # read Excel file into a pandas dataframe
    df = pd.read_excel(output_excel_path)

    # select the column you want to count values in
    column_name = "Test Result"
    column = df[column_name]

    # # count the number of occurrences of each value
    # pass_count = column.value_counts()["PASS"] #--pass_count
    # fail_count = column.value_counts()["FAIL"] #--fail_count
    # not_tested_count = column.value_counts()["NOT TESTED"] #--not_tested_count

    # # print the results
    # print("PASS count:", pass_count) if print_var == True else None
    # print("FAIL count:", fail_count) if print_var == True else None
    # print("NOT TESTED count:", not_tested_count) if print_var == True else None

    # Test_Result = ['PASS', 'FAIL', 'NOT TESTED']
    
    # count the number of occurrences of each value
    if column.value_counts().get("PASS") is not None:
        pass_count = column.value_counts()["PASS"]
    else:
        not_tested_count = 0

    if column.value_counts().get("FAIL") is not None:
        fail_count = column.value_counts()["FAIL"]
    else:
        not_tested_count = 0

    if column.value_counts().get("NOT TESTED") is not None:
        not_tested_count = column.value_counts()["NOT TESTED"]
    else:
        not_tested_count = 0


    # print the results
    print("PASS count:", pass_count) if print_var == True else None
    print("FAIL count:", fail_count) if print_var == True else None
    print("NOT TESTED count:", not_tested_count) if print_var == True else None

    if not_tested_count != 0 and pass_count != 0 and fail_count != 0:
        Test_Result = ['PASS', 'FAIL', 'NOT TESTED']
    elif not_tested_count == 0:
        Test_Result = ['PASS', 'FAIL', ' ']
    elif pass_count == 0:
        Test_Result = [' ', 'FAIL', 'NOT TESTED']
    elif not_tested_count == 0:
        Test_Result = ['PASS', ' ', 'NOT TESTED']

    Test_Result_1 = ['PASS', 'FAIL', 'NOT TESTED']

    data = [pass_count, fail_count, not_tested_count]

    colour = ['green', 'red', 'yellow'] #---------colours of Analysis diagrams (green:pass, red:fail, yellow:not tested)

    # Creating explode data
    explode = (0.1, 0.0, 0.2)

    # Wedge properties
    wp = { 'linewidth' : 1, 'edgecolor' : "green" }

    # Creating plot
    fig, ax = plt.subplots(figsize =(10, 7))

    # bar = plt.figure(figsize = (10, 5))

    wedges, texts, autotexts = ax.pie(data,
                                    autopct = lambda pct: func(pct, data),
                                    explode = explode,
                                    labels = Test_Result,
                                    shadow = True,
                                    colors = colour,
                                    startangle = 90,
                                    wedgeprops = wp,
                                    textprops = dict(color ="black"))
    # Adding legend
    ax.legend(wedges, Test_Result_1,
            title ="Test Result",
            loc ="center left",
            bbox_to_anchor =(1, 0, 0.5, 1))

    plt.setp(autotexts, size = 8, weight ="bold")
    ax.set_title("Test Report")
    plt.savefig(output_pie_path) #-------------save output pie diagram in png format

    # creating the bar plot
    bar = plt.figure(figsize = (10, 5))
    plt.bar(Test_Result_1, data, color =colour,
            width = 0.4)

    plt.xlabel("Test Result") # plot label to x-axis of bar diagram
    plt.ylabel("Result Count") # plot label to y-axis of bar diagram
    plt.title("Test Report") # title to bar diagram

    plt.savefig(output_bar_path) #-------------save output bar plot in png format

    #####################################__GENERATE_HTML_REPORT__##############################################
    #------This section of code will take input of generated excel file and based on it, will generate->#
    #------HTML Report "Report" showing test result of each signal (PASS, FAIL, NOT TESTED)-------------------#
    ###########################################################################################################

    x=df1.values.tolist() #----------Take all data from output excel file and convert to list

    # Addign the list to a dataframe and appending values to it (added "TSTC_new" excel)
    df = pd.DataFrame(x, columns=['Sr.No.','Test Suite','Test Case', 'Message Name', 'Signal Name','Test Type','Description','Test Result'])

    #---This line creates a styled pandas DataFrame where the row labels are hidden, the cell values in the---#
    #---"Description" column are highlighted with a custom color, and the column widths for "Description"-----#
    #---and "Test Result" are set to 800px and 150px, respectively.-------------------------------------------#
    styler = df.style.hide(axis=0).applymap(highlight_color).set_properties(subset=['Description'], **{'width': '800px'}).set_properties(subset=['Test Result'], **{'width': '150px'})

    # Create the Jinja2 environment and loader
    env = jinja2.Environment(loader=jinja2.FileSystemLoader(f'{cwd}\\internal\\report'))

    # Load the template file
    # template = env.get_template(f'{cwd}\\internal\\report\\tab_report.html')
    template = env.get_template('tab_report.html')
    # Template handling
    html = template.render(my_table=styler.to_html())
    # Write the HTML file

    # get current date and time
    current_datetime = datetime.now()
    print(current_datetime)
    current_datetime = str(current_datetime).replace(" ",".")
    current_datetime = str(current_datetime).replace(":",".")
    time = current_datetime[:27]
    Report_path = f'{cwd}\\output\\report\\report_{variant}_{time}.html'
    with open(Report_path, 'w') as f:
        f.write(html)

    if Debug():
        print(f"Reportfilepath: {Report_path}")
    return Report_path
    ##############################################__CODE_ENDS_HERE__###########################################