###########################################################################################################
#                                                                                                         #
#                             ****** ARXML GENERATOR ******                                               #
#                                                                                                         #
#                                      RealThingks India                                                  #
#                                                                                                         #
###########################################################################################################

#---------------------------------------------------------------------------------------------------------#
#                                            DISCRIPTION                                                  #
#---------------------------------------------------------------------------------------------------------#
# This script is writen to generate the ARXML by taking the input from the Excel file. This code uses     #
# the pandas library for accessing the value from excel sheet.                                            #
#                                                                                                         #
# The layout or format of the excel file must be same as the considered one. if there is any change in    #
#  the Excel sheet format then you have to adapt the code accordingly as this code is accessing the data  #
#  by coloumn by coloumn.                                                                                 #
#                                                                                                         #
#                                                                                                         #
#---------------------------------------------------------------------------------------------------------#
#                                            v.RELEASE                                                    #
#---------------------------------------------------------------------------------------------------------#
# Update :                                                                                                #
#   <version>  <Responsible>   <date>     : Added Feature                                                 #
#                                                                                                         #
#    v1.1.0     Suraj B.     16.12.2022   : Create the ARXMl for RAFT_SWC for P-PORT & R-PORT without     #
#                                               any configuration.                                        #
#    v1.2.0     Suraj B.     13.01.2023   : Using autosar module create PORTS and Runnable and do config. #
#---------------------------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------------------------#
#                                            IMPORTS                                                      #
#---------------------------------------------------------------------------------------------------------#
import autosar
import os
import pandas as pd 
import sys
import shutil

# class arxmlgenerator:
#     def __init__(self,Excelfilepath,arxmlfilepath):
#         self.Excelfilepath = Excelfilepath
#         self.arxmlfilepath = arxmlfilepath

global debug
debug =False


global cwd
cwd= os.getcwd()
if debug==True:
    print(cwd)
cwd= str(cwd).replace("/","\\")


def arxmlgenerator(file_path,Direction):
    #---------------------------------------------------------------------------------------------------------#
    #                                            reading DBC file                                             #
    #---------------------------------------------------------------------------------------------------------#

    # argv[1] - dbc parsed Excel path 
    # argv[2] - Output RAFT_SWC.arxml path
    # argv[3] -  dcm_swc path

    # dbc_Excel_file_path  = (sys.argv[1])
    # dbc_Excel_file_path = dbc_Excel_file_path.replace('/','\\')

    # print("Entered file path is not valid")
    # path of DBC Excel file
    # dbc_Excel_file_path = ("C:\\Users\\SurajBiradar\\Desktop\\RAFT\\Development_RAFT\\PythonScripts\\RAFT_SWC\\Input\\excelsheet\\final_list_dbc.xlsx")
    
    # Read_Excel_File = pd.read_excel(dbc_Excel_file_path)
    Read_Excel_File = pd.read_excel(file_path)
    if Direction:
        Read_Excel_File['Direction'] = 'Tx'
        Read_Excel_File['Check Box'] = 1
        Read_Excel_File['Port Type'] = 1
    else:
        Read_Excel_File['Direction'] = 'Rx'
        Read_Excel_File['Check Box'] = 1
        Read_Excel_File['Port Type'] = 1
    
    
    TxRxMethod = []
    cycle_time = (Read_Excel_File['Cycle_Time'])
    # reading the Excel file data by accessing the coloumns
    signals_name        = (Read_Excel_File['Signal_Name'])   # Access signal name
    length_signals_name = len(signals_name)    # no of signals
    Direction_signal    = (Read_Excel_File['Direction'])  # get the direction of Signals
    signal_init_value   = (Read_Excel_File['Init Value'])  # Get the Init value of signal
    value_type          = (Read_Excel_File['Value Type'])  # get the value type for data type calculation
    signal_length       = (Read_Excel_File['Length [Bit]'])  # get signal length
    signal_unit         = (Read_Excel_File['Unit'])  # get the unit of signal
    signal_offset       = (Read_Excel_File['Offset'])  # offset value of signal
    signal_factor       = (Read_Excel_File['Factor'])  # Factor of signal
    signal_min_value    = (Read_Excel_File['Minimum'])  # minimum value of signal
    signal_max_value    = (Read_Excel_File['Maximum'])  # maximum value of signal

    signal_porttype     = (Read_Excel_File['Port Type']) # to check whether declaration is Implicit or explicit
    for i in range(0, length_signals_name):
        if cycle_time[i]==0:
            TxRxMethod.append('cyclic')
        else:
            TxRxMethod.append('spontaneous')

    Read_Excel_File['TxRxMethod'] = TxRxMethod


    # print(signal_checkbox)
    signal_method       = (Read_Excel_File['TxRxMethod'])   # get the method detials of signal like cyclic or Spontaneous.
    signal_checkbox     = (Read_Excel_File['Check Box']) # if signal want to check or not
    #---------------------------------------------------------------------------------------------------------#
    #                                            Creating a workspace for XML                                 #
    #---------------------------------------------------------------------------------------------------------#

    # selecting the version of Autosar
    ws = autosar.workspace(version="4.2.2") 

    # Creating the packages in Workspace
    datatypes = ws.createPackage('DataTypes', role='DataType')
    datatypes.createSubPackage('CompuMethods', role='CompuMethod')
    datatypes.createSubPackage('DataConstrs', role='DataConstraint')
    datatypes.createSubPackage('Units', role='Unit')
    basetypes = datatypes.createSubPackage('BaseTypes')
    portinterfaces = ws.createPackage('PortInterfaces', role="PortInterface")
    components = ws.createPackage('ComponentTypes', role='ComponentType')
    constants = ws.createPackage('Constants', role='Constant')

    #Create DataTypes
    # implimentation_datatype() for unsigned int
    basetypes.createSwBaseType('uint8', 8, nativeDeclaration='uint8')
    basetypes.createSwBaseType('uint16', 16, nativeDeclaration='uint16')
    basetypes.createSwBaseType('uint32', 32, nativeDeclaration='uint32')
    basetypes.createSwBaseType('uint64', 64, nativeDeclaration='uint64')
    basetypes.createSwBaseType('uint128', 128, nativeDeclaration='uint128')
    basetypes.createSwBaseType('uint256', 256, nativeDeclaration='uint256')
    # implimentation_datatype() for Signed int
    basetypes.createSwBaseType('sint8', 8, nativeDeclaration='sint8')
    basetypes.createSwBaseType('sint16', 16, nativeDeclaration='sint16')
    basetypes.createSwBaseType('sint32', 32, nativeDeclaration='sint32')
    basetypes.createSwBaseType('sint64', 64, nativeDeclaration='sint64')
    basetypes.createSwBaseType('sint128', 128, nativeDeclaration='sint128')
    basetypes.createSwBaseType('sint256', 256, nativeDeclaration='sint256')
    # implimentation_datatype() for Boolean
    basetypes.createSwBaseType('boolean', 8, encoding = 'BOOLEAN', nativeDeclaration='boolean')
    # implimentation_datatype() for float32
    basetypes.createSwBaseType('float32', 32, encoding = 'IEEE754', nativeDeclaration = 'float32')
    # implimentation_datatype() for float64
    basetypes.createSwBaseType('float64', 64, encoding = 'IEEE754', nativeDeclaration = 'float64')

    #---------------------------------------------------------------------------------------------------------#
    #                             Renaming the Signals according to the p and R type                          #
    #---------------------------------------------------------------------------------------------------------#
    # List to store the modified name of the signals BEFORE: Emm_I_Bus_Fl_Ampr
    #                          If it's R-PORT        AFTER  : RAFT_R_Emm_I_Bus_Fl_Ampr
    #                          If it's P-PORT        AFTER  : RAFT_P_Emm_I_Bus_Fl_Ampr


    signal_name_mod = []

    for i in range(0, length_signals_name):
        if(Direction_signal[i] == 'Rx'):
            signal_name_mod.append('RAFT_R_'+str(signals_name[i]))
        if(Direction_signal[i] == 'Tx'):
            signal_name_mod.append('RAFT_P_'+str(signals_name[i]))


    #---------------------------------------------------------------------------------------------------------#
    #                                     Creating implementation datatype ref                                #
    #---------------------------------------------------------------------------------------------------------#

    for i in range(0, length_signals_name):
        if((signal_checkbox[i])&(Direction_signal[i] == 'Rx')):
            datatypes.createImplementationDataType(signals_name[i],lowerLimit=0, upperLimit=255,baseTypeRef='/DataTypes/BaseTypes/uint8')
        if((signal_checkbox[i])&(Direction_signal[i] == 'Tx')):
            datatypes.createImplementationDataType(signals_name[i],lowerLimit=0, upperLimit=255,baseTypeRef='/DataTypes/BaseTypes/uint8')



    #---------------------------------------------------------------------------------------------------------#
    #                                            Creating the interface                                       #
    #---------------------------------------------------------------------------------------------------------#   

    for i in range(0, length_signals_name):
        if((signal_checkbox[i])&(Direction_signal[i] == 'Rx')): # proceed for signal if it is selected
            typeref ="""/DataTypes/ImplementationTypes/"""+ str(signals_name[i])
            portinterfaces.createSenderReceiverInterface(signals_name[i], autosar.element.DataElement(str(signals_name[i]),str(signals_name[i])))
        if((signal_checkbox[i])&(Direction_signal[i] == 'Tx')):  
            typeref ="""/DataTypes/ImplementationTypes/"""+ str(signals_name[i])
            portinterfaces.createSenderReceiverInterface(signals_name[i], autosar.element.DataElement(str(signals_name[i]),str(signals_name[i])))  

    #---------------------------------------------------------------------------------------------------------#
    #                                     C reating implementation datatype ref                               #
    #---------------------------------------------------------------------------------------------------------#

    # creating RAFT Software Components
    components = ws.find('/ComponentTypes')
    swc = components.createApplicationSoftwareComponent('RAFT_SWC', behaviorName = "RAFT_SWC_InternalBehavior")

    #---------------------------------------------------------------------------------------------------------#
    #                                     Creating PORTS                                                      #
    #---------------------------------------------------------------------------------------------------------#

    for i in range(0, length_signals_name):
        if((signal_checkbox[i])&(Direction_signal[i] == 'Rx')): # proceed for signal if it is selected
            swc.createRequirePort(str(signal_name_mod[i]), signals_name[i],initValue =int(signal_init_value[i]))
            
    # for i in range(0, length_signals_name):
    #     if((signal_checkbox[i])&(Direction_signal[i] == 'Tx')):
    #         swc.createProvidePort(str(signal_name_mod[i]), signals_name[i],initValue =int(signal_init_value[i]))       

    #---------------------------------------------------------------------------------------------------------#
    #                                     DCM Implementation                                                  #
    #---------------------------------------------------------------------------------------------------------#

    microsar = ws.createPackage('MICROSAR')
    dcm_swc  = microsar.createSubPackage('Dcm_swc', role='ComponentType')
    dcm_datatypes = dcm_swc.createSubPackage('DataTypes', role='DataType')
    dcm_interface = dcm_swc.createSubPackage('Interfaces', role='PortInterface')

    dcm_basetypes = dcm_datatypes.createSubPackage('BaseTypes')
    dcm_basetypes.createSwBaseType('uint8', 8, nativeDeclaration='uint8')

    dcm_datatypes.createImplementationDataType('uint8',lowerLimit=0, upperLimit=255,baseTypeRef='/DataTypes/BaseTypes/uint8')

    dcm_operation = dcm_interface.createClientServerInterface("DataServices_RAFT_TestDataIndetifier", operations = ["ReadData","ConditionCheckRead","WriteData"], errors = [autosar.ApplicationError("E_NOT_OK", 1),autosar.ApplicationError("DCM_E_PENDING", 10)], isService=True)
    swc.createProvidePort('DataServices_RAFT_TestDataIndetifier','DataServices_RAFT_TestDataIndetifier')

    dcm_operation["ReadData"].createInArgument("Dcm_OpStatusType", '/DataTypes/BaseTypes/uint8')
    dcm_operation["ReadData"].createOutArgument("Dcm_Data8ByteType", '/DataTypes/BaseTypes/uint8')

    dcm_operation["ConditionCheckRead"].createInArgument("Dcm_OpStatusType", '/DataTypes/BaseTypes/uint8')
    dcm_operation["ConditionCheckRead"].createOutArgument("Dcm_NegativeResponseCodeType", '/DataTypes/BaseTypes/uint8')

    dcm_operation["WriteData"].createInArgument("Dcm_OpStatusType", '/DataTypes/BaseTypes/uint8')
    dcm_operation["WriteData"].createInArgument("Dcm_Data8ByteType", '/DataTypes/BaseTypes/uint8')
    dcm_operation["WriteData"].createOutArgument("Dcm_NegativeResponseCodeType", '/DataTypes/BaseTypes/uint8')

    #---------------------------------------------------------------------------------------------------------#
    #                                     Creating Runnables for RAFT_SWC and DCM implementation              #
    #---------------------------------------------------------------------------------------------------------#

    # # if you are using not using explicit or implicit method then comment below line of code
    # PortAcccess_name = []
    # for i in range(0, length_signals_name):
    #     if((signal_checkbox[i])&(Direction_signal[i] == 'Rx')): # proceed for signal if it is selected
    #             PortAcccess_name.append(signals_name[i])

    # swc.behavior.createRunnable('RAFT_SWC_Main',portAccess=PortAcccess_name)


    ####################################### only for Implicit or Explicit######################################
    # List to store the Implicit signals
    PortAcccess_name_implicit = []
    # List to store the Explicit signals
    PortAcccess_name_Explicit = []

    # Store the signal name based on the Implicit or Explicit in the above list at a perticular locations only.
    for i in range(0, length_signals_name):
        if((signal_checkbox[i])&(Direction_signal[i] == 'Rx')&(signal_porttype[i])): # proceed for signal if it is selected & if Explicit
            PortAcccess_name_Explicit.append(signal_name_mod[i])
        if((signal_checkbox[i])&(Direction_signal[i] == 'Rx')): # proceed for signal if it is selected & if Implicit
            PortAcccess_name_implicit.append(signal_name_mod[i])

    # FIND HOW MANY PORT SARE DECLARED AS IMPLICIT
    len_implicit_port = len(PortAcccess_name_implicit)
    # print(len_implicit_port)


    # if post access is Implicit
    swc.behavior.createRunnable('RAFT_SWC_Main',portAccess=PortAcccess_name_implicit)

    # if post access is Explicit
    swc.behavior.createRunnable('RAFT_SWC_Main',portAccess=PortAcccess_name_Explicit)
    ##########################################################################################################



    # adding the peroidic time of 10ms for RAFT_SWC_Main Runnable
    swc.behavior.createTimerEvent('RAFT_SWC_Main',10)
    swc.behavior.createRunnable('RAFT_SWC_Init')
    swc.behavior.createInitEvent('RAFT_SWC_Init')

    swc.behavior.createRunnable('DataServices_RAFT_TestDataIndetifier_WriteData')
    swc.behavior.createOperationInvokedEvent('DataServices_RAFT_TestDataIndetifier_WriteData',str('DataServices_RAFT_TestDataIndetifier/WriteData'))

    swc.behavior.createRunnable('DataServices_RAFT_TestDataIndetifier_ConditionCheckRead')
    swc.behavior.createOperationInvokedEvent('DataServices_RAFT_TestDataIndetifier_ConditionCheckRead',str('DataServices_RAFT_TestDataIndetifier/ConditionCheckRead'))

    swc.behavior.createRunnable('DataServices_RAFT_TestDataIndetifier_ReadData')
    swc.behavior.createOperationInvokedEvent('DataServices_RAFT_TestDataIndetifier_ReadData',str('DataServices_RAFT_TestDataIndetifier/ReadData'))


    #---------------------------------------------------------------------------------------------------------#
    #                                     Saving Workspace and generating a file                              #
    #---------------------------------------------------------------------------------------------------------#

    # dest_dir = sys.argv[2]
    # dest_dir = dest_dir.replace('/','\\')


    # output file path
    dest_dir = f"{cwd}\\output\\arxml"

    for swc in ws.findall("/ComponentTypes/*"):
        if isinstance(swc, autosar.component.ComponentType):
            filters = ["/ComponentTypes/" + swc.name, "/ComponentTypes/{0.name}_Implementation".format(swc)]
            dest_file = os.path.join(dest_dir, "{0.name}.arxml".format(swc))
            ws.saveXML(dest_file, filters)

    dest_file_generated = str(dest_dir) + str("\\RAFT_SWC.arxml")
    with open(dest_file_generated) as file:
        data = str(file.read())

    #remove half configured XML 
    os.remove(dest_file_generated)   

    # print(data)

    # for Delement in data.find("<DATA-RECEIVE-POINT-BY-ARGUMENTS>"):
    #     new_s = Delement.replace("<DATA-RECEIVE-POINT-BY-ARGUMENTS>","<DATA-READ-ACCESSS>")

    ######################## only for Implicit or Explicit###############################
    # new_s = data.replace("<DATA-RECEIVE-POINT-BY-ARGUMENTS>","<DATA-READ-ACCESSS>")
    # new_s1 = new_s.replace("</DATA-RECEIVE-POINT-BY-ARGUMENTS>","</DATA-READ-ACCESSS>")
    # new_s2 = data.replace("IT_RAFT_SWC_Init","RAFT_SWC_InitEvent")
    ##################################################################################

    # This is additional steps that will required to mapped the Implicit and Explicit data element access by Main Port
    new_s = data.replace("<DATA-RECEIVE-POINT-BY-ARGUMENTS>","<DATA-READ-ACCESSS>",1) 
    new_s1 = new_s.replace("</DATA-RECEIVE-POINT-BY-ARGUMENTS>","</DATA-READ-ACCESSS>",1)
    # if you are using exmplit or implicit methiond then comment below line of code
    new_s2 = new_s1.replace("IT_RAFT_SWC_Init","RAFT_SWC_InitEvent",1)
    new_s3 = new_s2.replace('''                  <SYMBOL>RAFT_SWC_Main</SYMBOL>
                    </RUNNABLE-ENTITY>
                    <RUNNABLE-ENTITY>
                    <SHORT-NAME>RAFT_SWC_Main</SHORT-NAME>
                    <MINIMUM-START-INTERVAL>0</MINIMUM-START-INTERVAL>
                    <CAN-BE-INVOKED-CONCURRENTLY>false</CAN-BE-INVOKED-CONCURRENTLY>''',"",1)
    new_s4 = "\n".join([ll.rstrip() for ll in new_s3.splitlines() if ll.strip()]) # to remove the Emplty line created by above command
    new_s5 = new_s4.replace("<SHORT-NAME>REC_","<SHORT-NAME>READ_",int(len_implicit_port))
    # print(new_s2)

    final_xml_output_path =  str(dest_dir)+ str("\RAFT_SWC.arxml")
    # final_xml_output_path =  str(sys.argv[2])+ str("\RAFT_SWC.arxml")
    with open(final_xml_output_path,"w") as file1:
        file1.write(new_s5)

    # move generated ARXML file into /Output folder
    # shutil.move("RAFT_SWC\\..\\RAFT_XML.arxml", "RAFT_SWC\\..\\Output\\RAFT_SWC.arxml")    
    # ws.saveXML(dest_file,'{}.arxml'.format(swc.name),filters=['/ComponentTypes/{}'.format(swc.name)])
    # ws.saveXML('{}.arxml'.format(swc.name),filters=['/ComponentTypes/{}'.format(swc.name)])