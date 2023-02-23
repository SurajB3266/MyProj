###########################################################################################################
#                                                                                                         #
#                             ****** ARXML GENERATOR ******                                               #
#                                                                                                         #
#                                    RealThingks India                                                    #
#                                                                                                         #
###########################################################################################################

#---------------------------------------------------------------------------------------------------------#
#                                            DISCRIPTION                                                  #
#---------------------------------------------------------------------------------------------------------#
# This scripts will do the necessary modifaication that are needed to add the DID of RAFT in Dcm_swc      #
#                                                                                                         #
# how to Run sing CLI                                                                                     #
#  python3 .\03_add_DIDinDcm_swc.py <Path_of_Dcm_swc> <output_file_path>                                  #
#                                                                                                         #
#---------------------------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------------------------#
#                                            v.RELEASE                                                    #
#---------------------------------------------------------------------------------------------------------#
# Update :                                                                                                #
#   <version>  <Responsible>   <date>     : Added Feature                                                 #
#                                                                                                         #
#    v1.1.0     Suraj B.     23.01.2023   : Added RAFT DID in Dcm_swc                                     #
#                                                                                                         #
#---------------------------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------------------------#
#                                            IMPORTS                                                      #
#---------------------------------------------------------------------------------------------------------#
import os
import sys


global cwd
cwd = os.getcwd() # getting CWD path
cwd = str(cwd).replace('/','\\')

def Createdcmarxml(path):
    #---------------------------------------------------------------------------------------------------------#
    #                                gething path fdpor Dcm_swc and output file path                          #
    #---------------------------------------------------------------------------------------------------------#

    # if Dcm_swc arxml is the 2 arggumentb of the command
    # dcm_path = sys.argv[1]
    dcm_path = path
    dcm_path = dcm_path.replace('/','\\')
    # dcm_path = dcm_path.replace('/','\\')
    # print(dcm_path)

    # output_dcmPath = sys.argv[2]
    output_dcmPath = f"{cwd}\\output\\arxml"
    # dcm_path = "C:\\Users\\SurajBiradar\\Desktop\\RAFT\\Development_RAFT\\IntegrationV0.1\\1_st_release\\output"
    # dcm_path = f"{cwd}\\input\\arxml\\Dcm_swc.arxml"
    # dcm_path = dcm_path.replace('/','\\')

    # dcm_path = "C:\\Users\\SurajBiradar\\Desktop\\RAFT\\Dcm_swc.arxml"
    with open(dcm_path) as file:
        dcm_data = str(file.read())

    #---------------------------------------------------------------------------------------------------------#
    #                                Adding DID in Dcm_swc                                                    #
    #---------------------------------------------------------------------------------------------------------#
    # adding Implementation datatype in Dcm_swc
    dcm_datatype = dcm_data.replace('''              <SHORT-NAME>DataTypes</SHORT-NAME>
                <ELEMENTS>''','''              <SHORT-NAME>DataTypes</SHORT-NAME>
                <ELEMENTS>
                    <IMPLEMENTATION-DATA-TYPE>
                    <SHORT-NAME>Dcm_Data8ByteType</SHORT-NAME>
                    <CATEGORY>ARRAY</CATEGORY>
                    <SW-DATA-DEF-PROPS>
                        <SW-DATA-DEF-PROPS-VARIANTS>
                        <SW-DATA-DEF-PROPS-CONDITIONAL>
                            <SW-CALIBRATION-ACCESS>READ-ONLY</SW-CALIBRATION-ACCESS>
                        </SW-DATA-DEF-PROPS-CONDITIONAL>
                        </SW-DATA-DEF-PROPS-VARIANTS>
                    </SW-DATA-DEF-PROPS>
                    <SUB-ELEMENTS>
                        <IMPLEMENTATION-DATA-TYPE-ELEMENT>
                        <SHORT-NAME>Dcm_Data8ByteTypeElement</SHORT-NAME>
                        <CATEGORY>TYPE_REFERENCE</CATEGORY>
                        <ARRAY-SIZE>8</ARRAY-SIZE>
                        <ARRAY-SIZE-SEMANTICS>FIXED-SIZE</ARRAY-SIZE-SEMANTICS>
                        <SW-DATA-DEF-PROPS>
                            <SW-DATA-DEF-PROPS-VARIANTS>
                            <SW-DATA-DEF-PROPS-CONDITIONAL>
                                <IMPLEMENTATION-DATA-TYPE-REF DEST="IMPLEMENTATION-DATA-TYPE">/AUTOSAR_Platform/ImplementationDataTypes/uint8</IMPLEMENTATION-DATA-TYPE-REF>
                            </SW-DATA-DEF-PROPS-CONDITIONAL>
                            </SW-DATA-DEF-PROPS-VARIANTS>
                        </SW-DATA-DEF-PROPS>
                        </IMPLEMENTATION-DATA-TYPE-ELEMENT>
                    </SUB-ELEMENTS>
                    </IMPLEMENTATION-DATA-TYPE>''',1)

    Dcm_data_1 = dcm_datatype.replace('''                  </MODE-GROUP>
                    </MODE-SWITCH-INTERFACE''','''                  </MODE-GROUP>
                    </MODE-SWITCH-INTERFACE>
                    <CLIENT-SERVER-INTERFACE>
                    <SHORT-NAME>DataServices_RAFT_TestDataIndetifier</SHORT-NAME>
                    <IS-SERVICE>true</IS-SERVICE>
                    <SERVICE-KIND>DIAGNOSTIC-COMMUNICATION-MANAGER</SERVICE-KIND>
                    <OPERATIONS>
                        <CLIENT-SERVER-OPERATION>
                        <SHORT-NAME>ReadData</SHORT-NAME>
                        <DESC>
                            <L-2 L="FOR-ALL"/>
                        </DESC>
                        <ARGUMENTS>
                            <ARGUMENT-DATA-PROTOTYPE>
                            <SHORT-NAME>OpStatus</SHORT-NAME>
                            <DESC>
                                <L-2 L="FOR-ALL"/>
                            </DESC>
                            <TYPE-TREF DEST="IMPLEMENTATION-DATA-TYPE">/MICROSAR/Dcm_swc/DataTypes/Dcm_OpStatusType</TYPE-TREF>
                            <DIRECTION>IN</DIRECTION>
                            </ARGUMENT-DATA-PROTOTYPE>
                            <ARGUMENT-DATA-PROTOTYPE>
                            <SHORT-NAME>Data</SHORT-NAME>
                            <DESC>
                                <L-2 L="FOR-ALL"/>
                            </DESC>
                            <TYPE-TREF DEST="IMPLEMENTATION-DATA-TYPE">/MICROSAR/Dcm_swc/DataTypes/Dcm_Data8ByteType</TYPE-TREF>
                            <DIRECTION>OUT</DIRECTION>
                            </ARGUMENT-DATA-PROTOTYPE>
                        </ARGUMENTS>
                        <POSSIBLE-ERROR-REFS>
                            <POSSIBLE-ERROR-REF DEST="APPLICATION-ERROR">/MICROSAR/Dcm_swc/Interfaces/DataServices_RAFT_TestDataIndetifier/E_NOT_OK</POSSIBLE-ERROR-REF>
                            <POSSIBLE-ERROR-REF DEST="APPLICATION-ERROR">/MICROSAR/Dcm_swc/Interfaces/DataServices_RAFT_TestDataIndetifier/DCM_E_PENDING</POSSIBLE-ERROR-REF>
                        </POSSIBLE-ERROR-REFS>
                        </CLIENT-SERVER-OPERATION>
                        <CLIENT-SERVER-OPERATION>
                        <SHORT-NAME>ConditionCheckRead</SHORT-NAME>
                        <DESC>
                            <L-2 L="FOR-ALL"/>
                        </DESC>
                        <ARGUMENTS>
                            <ARGUMENT-DATA-PROTOTYPE>
                            <SHORT-NAME>OpStatus</SHORT-NAME>
                            <DESC>
                                <L-2 L="FOR-ALL"/>
                            </DESC>
                            <TYPE-TREF DEST="IMPLEMENTATION-DATA-TYPE">/MICROSAR/Dcm_swc/DataTypes/Dcm_OpStatusType</TYPE-TREF>
                            <DIRECTION>IN</DIRECTION>
                            </ARGUMENT-DATA-PROTOTYPE>
                            <ARGUMENT-DATA-PROTOTYPE>
                            <SHORT-NAME>ErrorCode</SHORT-NAME>
                            <DESC>
                                <L-2 L="FOR-ALL"/>
                            </DESC>
                            <TYPE-TREF DEST="IMPLEMENTATION-DATA-TYPE">/MICROSAR/Dcm_swc/DataTypes/Dcm_NegativeResponseCodeType</TYPE-TREF>
                            <DIRECTION>OUT</DIRECTION>
                            </ARGUMENT-DATA-PROTOTYPE>
                        </ARGUMENTS>
                        <POSSIBLE-ERROR-REFS>
                            <POSSIBLE-ERROR-REF DEST="APPLICATION-ERROR">/MICROSAR/Dcm_swc/Interfaces/DataServices_RAFT_TestDataIndetifier/E_NOT_OK</POSSIBLE-ERROR-REF>
                            <POSSIBLE-ERROR-REF DEST="APPLICATION-ERROR">/MICROSAR/Dcm_swc/Interfaces/DataServices_RAFT_TestDataIndetifier/DCM_E_PENDING</POSSIBLE-ERROR-REF>
                        </POSSIBLE-ERROR-REFS>
                        </CLIENT-SERVER-OPERATION>
                        <CLIENT-SERVER-OPERATION>
                        <SHORT-NAME>WriteData</SHORT-NAME>
                        <DESC>
                            <L-2 L="FOR-ALL"/>
                        </DESC>
                        <ARGUMENTS>
                            <ARGUMENT-DATA-PROTOTYPE>
                            <SHORT-NAME>Data</SHORT-NAME>
                            <DESC>
                                <L-2 L="FOR-ALL"/>
                            </DESC>
                            <TYPE-TREF DEST="IMPLEMENTATION-DATA-TYPE">/MICROSAR/Dcm_swc/DataTypes/Dcm_Data8ByteType</TYPE-TREF>
                            <DIRECTION>IN</DIRECTION>
                            </ARGUMENT-DATA-PROTOTYPE>
                            <ARGUMENT-DATA-PROTOTYPE>
                            <SHORT-NAME>OpStatus</SHORT-NAME>
                            <DESC>
                                <L-2 L="FOR-ALL"/>
                            </DESC>
                            <TYPE-TREF DEST="IMPLEMENTATION-DATA-TYPE">/MICROSAR/Dcm_swc/DataTypes/Dcm_OpStatusType</TYPE-TREF>
                            <DIRECTION>IN</DIRECTION>
                            </ARGUMENT-DATA-PROTOTYPE>
                            <ARGUMENT-DATA-PROTOTYPE>
                            <SHORT-NAME>ErrorCode</SHORT-NAME>
                            <DESC>
                                <L-2 L="FOR-ALL"/>
                            </DESC>
                            <TYPE-TREF DEST="IMPLEMENTATION-DATA-TYPE">/MICROSAR/Dcm_swc/DataTypes/Dcm_NegativeResponseCodeType</TYPE-TREF>
                            <DIRECTION>OUT</DIRECTION>
                            </ARGUMENT-DATA-PROTOTYPE>
                        </ARGUMENTS>
                        <POSSIBLE-ERROR-REFS>
                            <POSSIBLE-ERROR-REF DEST="APPLICATION-ERROR">/MICROSAR/Dcm_swc/Interfaces/DataServices_RAFT_TestDataIndetifier/E_NOT_OK</POSSIBLE-ERROR-REF>
                            <POSSIBLE-ERROR-REF DEST="APPLICATION-ERROR">/MICROSAR/Dcm_swc/Interfaces/DataServices_RAFT_TestDataIndetifier/DCM_E_PENDING</POSSIBLE-ERROR-REF>
                        </POSSIBLE-ERROR-REFS>
                        </CLIENT-SERVER-OPERATION>
                    </OPERATIONS>
                    <POSSIBLE-ERRORS>
                        <APPLICATION-ERROR>
                        <SHORT-NAME>E_NOT_OK</SHORT-NAME>
                        <ERROR-CODE>1</ERROR-CODE>
                        </APPLICATION-ERROR>
                        <APPLICATION-ERROR>
                        <SHORT-NAME>DCM_E_PENDING</SHORT-NAME>
                        <ERROR-CODE>10</ERROR-CODE>
                        </APPLICATION-ERROR>
                    </POSSIBLE-ERRORS>
                    </CLIENT-SERVER-INTERFACE>''',1)
    # adding R-Port to Dcm_swc
    dcm_data_2 =Dcm_data_1.replace('''                  <SHORT-NAME>Dcm</SHORT-NAME>
                    <CATEGORY>SERVICE_COMPONENT</CATEGORY>
                    <PORTS>''','''                  <SHORT-NAME>Dcm</SHORT-NAME>
                    <CATEGORY>SERVICE_COMPONENT</CATEGORY>
                    <PORTS>
                        <R-PORT-PROTOTYPE>
                        <SHORT-NAME>DataServices_RAFT_TestDataIndetifier</SHORT-NAME>
                        <ADMIN-DATA>
                            <SDGS>
                            <SDG GID="DV:ValidPostBuildVariants">
                                <SDX-REF DEST="PREDEFINED-VARIANT">/VariantDefinition/Variant/FL</SDX-REF>
                                <SDX-REF DEST="PREDEFINED-VARIANT">/VariantDefinition/Variant/FR</SDX-REF>
                                <SDX-REF DEST="PREDEFINED-VARIANT">/VariantDefinition/Variant/RL</SDX-REF>
                                <SDX-REF DEST="PREDEFINED-VARIANT">/VariantDefinition/Variant/RR</SDX-REF>
                            </SDG>
                            <SDG GID="DV:DerivedFromReferrables">
                                <SDG GID="DV:DerivedFromReferrablesVariant">
                                <SDX-REF DEST="PREDEFINED-VARIANT">/VariantDefinition/Variant/FL</SDX-REF>
                                <SDX-REF DEST="ECUC-CONTAINER-VALUE">/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/RAFT_TestDataIndetifier</SDX-REF>
                                </SDG>
                                <SDG GID="DV:DerivedFromReferrablesVariant">
                                <SDX-REF DEST="PREDEFINED-VARIANT">/VariantDefinition/Variant/FR</SDX-REF>
                                <SDX-REF DEST="ECUC-CONTAINER-VALUE">/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/RAFT_TestDataIndetifier</SDX-REF>
                                </SDG>
                                <SDG GID="DV:DerivedFromReferrablesVariant">
                                <SDX-REF DEST="PREDEFINED-VARIANT">/VariantDefinition/Variant/RL</SDX-REF>
                                <SDX-REF DEST="ECUC-CONTAINER-VALUE">/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/RAFT_TestDataIndetifier</SDX-REF>
                                </SDG>
                                <SDG GID="DV:DerivedFromReferrablesVariant">
                                <SDX-REF DEST="PREDEFINED-VARIANT">/VariantDefinition/Variant/RR</SDX-REF>
                                <SDX-REF DEST="ECUC-CONTAINER-VALUE">/ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/RAFT_TestDataIndetifier</SDX-REF>
                                </SDG>
                            </SDG>
                            </SDGS>
                        </ADMIN-DATA>
                        <REQUIRED-INTERFACE-TREF DEST="CLIENT-SERVER-INTERFACE">/MICROSAR/Dcm_swc/Interfaces/DataServices_RAFT_TestDataIndetifier</REQUIRED-INTERFACE-TREF>
                        </R-PORT-PROTOTYPE>''',1)

    dcm_data_3 = dcm_data_2.replace('''                      <PORT-API-OPTIONS>''','''                      <PORT-API-OPTIONS>
                            <PORT-API-OPTION>
                            <ENABLE-TAKE-ADDRESS>true</ENABLE-TAKE-ADDRESS>
                            <INDIRECT-API>false</INDIRECT-API>
                            <PORT-REF DEST="R-PORT-PROTOTYPE">/MICROSAR/Dcm_swc/ComponentTypes/Dcm/DataServices_RAFT_TestDataIndetifier</PORT-REF>
                            </PORT-API-OPTION>''',1)

    dcm_data_4 = dcm_data_3.replace('''                          </MODE-SWITCH-POINTS>
                            <SERVER-CALL-POINTS>''','''                          </MODE-SWITCH-POINTS>
                            <SERVER-CALL-POINTS>
                                <SYNCHRONOUS-SERVER-CALL-POINT>
                                <SHORT-NAME>OpServerCallDcm_MainFunction_ReadData_DataServices_RAFT_TestDataIndetifier</SHORT-NAME>
                                <OPERATION-IREF>
                                    <CONTEXT-R-PORT-REF DEST="R-PORT-PROTOTYPE">/MICROSAR/Dcm_swc/ComponentTypes/Dcm/DataServices_RAFT_TestDataIndetifier</CONTEXT-R-PORT-REF>
                                    <TARGET-REQUIRED-OPERATION-REF DEST="CLIENT-SERVER-OPERATION">/MICROSAR/Dcm_swc/Interfaces/DataServices_RAFT_TestDataIndetifier/ReadData</TARGET-REQUIRED-OPERATION-REF>
                                </OPERATION-IREF>
                                <TIMEOUT>0</TIMEOUT>
                                </SYNCHRONOUS-SERVER-CALL-POINT>
                                <SYNCHRONOUS-SERVER-CALL-POINT>
                                <SHORT-NAME>OpServerCallDcm_MainFunction_ConditionCheckRead_DataServices_RAFT_TestDataIndetifier</SHORT-NAME>
                                <OPERATION-IREF>
                                    <CONTEXT-R-PORT-REF DEST="R-PORT-PROTOTYPE">/MICROSAR/Dcm_swc/ComponentTypes/Dcm/DataServices_RAFT_TestDataIndetifier</CONTEXT-R-PORT-REF>
                                    <TARGET-REQUIRED-OPERATION-REF DEST="CLIENT-SERVER-OPERATION">/MICROSAR/Dcm_swc/Interfaces/DataServices_RAFT_TestDataIndetifier/ConditionCheckRead</TARGET-REQUIRED-OPERATION-REF>
                                </OPERATION-IREF>
                                <TIMEOUT>0</TIMEOUT>
                                </SYNCHRONOUS-SERVER-CALL-POINT>
                                <SYNCHRONOUS-SERVER-CALL-POINT>
                                <SHORT-NAME>OpServerCallDcm_MainFunction_WriteData_DataServices_RAFT_TestDataIndetifier</SHORT-NAME>
                                <OPERATION-IREF>
                                    <CONTEXT-R-PORT-REF DEST="R-PORT-PROTOTYPE">/MICROSAR/Dcm_swc/ComponentTypes/Dcm/DataServices_RAFT_TestDataIndetifier</CONTEXT-R-PORT-REF>
                                    <TARGET-REQUIRED-OPERATION-REF DEST="CLIENT-SERVER-OPERATION">/MICROSAR/Dcm_swc/Interfaces/DataServices_RAFT_TestDataIndetifier/WriteData</TARGET-REQUIRED-OPERATION-REF>
                                </OPERATION-IREF>
                                <TIMEOUT>0</TIMEOUT>
                                </SYNCHRONOUS-SERVER-CALL-POINT>''',1)

    #---------------------------------------------------------------------------------------------------------#
    #                                creating the output file                                                 #
    #---------------------------------------------------------------------------------------------------------#


    output_dcmPath = str(output_dcmPath)+"\\Dcm_swc.arxml"
    # writing a new arxml at the original location
    with open(output_dcmPath,"w") as file1:
        file1.write(dcm_data_4)
    file1.close()

        