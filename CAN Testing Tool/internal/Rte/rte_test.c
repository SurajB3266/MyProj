

        uint8 retval_u8 = E_NOT_OK;
        uint8 RAFT_Resp_Result_u8[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};  
    
        Ascc_St_Req_Na Asmc_Req_DaHlthTest_Na_sig;
    
        Asmc_1000Hz_F_Cmd_AlvCtr Ascc_St_Req_Na_sig;
    
        Asmc_1000Hz_F_Cmd_Crc Asmc_25Hz_Sts_AlvCtr_sig;
    
        Asmc_100Hz_Sts_VehStaty_AlvCtr Fas_Sts_VehStsSpdLo_Qfr_Na_sig;
    
        Asmc_100Hz_Sts_VehStaty_Crc Fas_Sts_VehSpdLo_Na_sig;
    
        Asmc_100Hz_Zl_Mofr_AlvCtr Fas_Sts_VehStsStaty_Qfr_Na_sig;
    
        Asmc_25Hz_Sts_AlvCtr Fas_Sts_VehStaty_Na_sig;
    
        Asmc_Req_DaHlthTest_Na Asmc_100Hz_Sts_VehStaty_Crc_sig;
    
        sint16 Asmc_100Hz_Sts_VehStaty_AlvCtr_sig;
    
        sint16 Faa_Sts_F_Qfr_Na_sig;
    
        sint16 Faa_F_Rr_AtActr_Cmd_Nwt_sig;
    
        sint16 Faa_F_Rl_AtActr_Cmd_Nwt_sig;
    
        uint8 Faa_F_Fr_AtActr_Cmd_Nwt_sig;
    
        uint8 Faa_F_Fl_AtActr_Cmd_Nwt_sig;
    
        uint8 Asmc_1000Hz_F_Cmd_Crc_sig;
    
        uint8 Asmc_1000Hz_F_Cmd_AlvCtr_sig;
    
        uint8 Faa_Sts_ZlMofr_Re_Qfr_Na_sig;
    
        uint8 Faa_Gain_Re_ZlFil_Na_sig;
    
        Faa_Sts_F_Qfr_Na Faa_Wi_Re_ZlFil_Na_sig;
    
        Faa_Sts_ZlMofr_Fn_Qfr_Na Faa_Frq_Re_ZlFil_Ce_Hz_sig;
    
        Faa_Sts_ZlMofr_Re_Qfr_Na Faa_Mofr_Re_ZlGain_Na_sig;
    
        uint8 Faa_Sts_ZlMofr_Fn_Qfr_Na_sig;
    
        uint8 Faa_Gain_Fn_ZlFil_Na_sig;
    
        Fas_Sts_VehSpdLo_Na Faa_Wi_Fn_ZlFil_Na_sig;
    
        Fas_Sts_VehStaty_Na Faa_Frq_Fn_ZlFil_Ce_Hz_sig;
    
        Fas_Sts_VehStsSpdLo_Qfr_Na Faa_Mofr_Fn_ZlGain_Na_sig;
    
        Fas_Sts_VehStsStaty_Qfr_Na Asmc_100Hz_Zl_Mofr_AlvCtr_sig;
    
            /*Read the RAFT Test request signal*/
            /*RAFT Req. Signal format
            * Byte 0: Test Suite Number
            * Byte 1: Test Case Number
            * Byte 2 to n: Test value needed for the test*/
        switch (Data[0])
        {
    
            case Suite_0: 
                switch (Data[1])
                { 
    
                    case TestCase_0: 
                        Asmc_Req_DaHlthTest_Na_sig = Rte_IRead_RAFT_SWC_Main_Ascc_St_Req_Na_Ascc_St_Req_Na();
                        if (Asmc_Req_DaHlthTest_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[0] = Suite_0;
                            RAFT_Resp_Result_u8[1] = TestCase_0;
                            RAFT_Resp_Result_u8[2] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[0] = Suite_0;
                            RAFT_Resp_Result_u8[1] = TestCase_0;
                            RAFT_Resp_Result_u8[2] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_1: 
                        Asmc_Req_DaHlthTest_Na_sig = Rte_IRead_RAFT_SWC_Main_Ascc_St_Req_Na_Ascc_St_Req_Na();
                        if (Asmc_Req_DaHlthTest_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[3] = Suite_0;
                            RAFT_Resp_Result_u8[4] = TestCase_1;
                            RAFT_Resp_Result_u8[5] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[3] = Suite_0;
                            RAFT_Resp_Result_u8[4] = TestCase_1;
                            RAFT_Resp_Result_u8[5] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_2: 
                        Asmc_Req_DaHlthTest_Na_sig = Rte_IRead_RAFT_SWC_Main_Ascc_St_Req_Na_Ascc_St_Req_Na();
                        if (Asmc_Req_DaHlthTest_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[6] = Suite_0;
                            RAFT_Resp_Result_u8[7] = TestCase_2;
                            RAFT_Resp_Result_u8[8] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[6] = Suite_0;
                            RAFT_Resp_Result_u8[7] = TestCase_2;
                            RAFT_Resp_Result_u8[8] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_3: 
                        Ascc_St_Req_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_1000Hz_F_Cmd_AlvCtr_Asmc_1000Hz_F_Cmd_AlvCtr();
                        if (Ascc_St_Req_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[9] = Suite_0;
                            RAFT_Resp_Result_u8[10] = TestCase_3;
                            RAFT_Resp_Result_u8[11] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[9] = Suite_0;
                            RAFT_Resp_Result_u8[10] = TestCase_3;
                            RAFT_Resp_Result_u8[11] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_4: 
                        Ascc_St_Req_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_1000Hz_F_Cmd_AlvCtr_Asmc_1000Hz_F_Cmd_AlvCtr();
                        if (Ascc_St_Req_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[12] = Suite_0;
                            RAFT_Resp_Result_u8[13] = TestCase_4;
                            RAFT_Resp_Result_u8[14] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[12] = Suite_0;
                            RAFT_Resp_Result_u8[13] = TestCase_4;
                            RAFT_Resp_Result_u8[14] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_5: 
                        Ascc_St_Req_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_1000Hz_F_Cmd_AlvCtr_Asmc_1000Hz_F_Cmd_AlvCtr();
                        if (Ascc_St_Req_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[15] = Suite_0;
                            RAFT_Resp_Result_u8[16] = TestCase_5;
                            RAFT_Resp_Result_u8[17] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[15] = Suite_0;
                            RAFT_Resp_Result_u8[16] = TestCase_5;
                            RAFT_Resp_Result_u8[17] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_6: 
                        Asmc_25Hz_Sts_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Asmc_1000Hz_F_Cmd_Crc_Asmc_1000Hz_F_Cmd_Crc();
                        if (Asmc_25Hz_Sts_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[18] = Suite_0;
                            RAFT_Resp_Result_u8[19] = TestCase_6;
                            RAFT_Resp_Result_u8[20] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[18] = Suite_0;
                            RAFT_Resp_Result_u8[19] = TestCase_6;
                            RAFT_Resp_Result_u8[20] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_7: 
                        Asmc_25Hz_Sts_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Asmc_1000Hz_F_Cmd_Crc_Asmc_1000Hz_F_Cmd_Crc();
                        if (Asmc_25Hz_Sts_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[21] = Suite_0;
                            RAFT_Resp_Result_u8[22] = TestCase_7;
                            RAFT_Resp_Result_u8[23] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[21] = Suite_0;
                            RAFT_Resp_Result_u8[22] = TestCase_7;
                            RAFT_Resp_Result_u8[23] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_8: 
                        Asmc_25Hz_Sts_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Asmc_1000Hz_F_Cmd_Crc_Asmc_1000Hz_F_Cmd_Crc();
                        if (Asmc_25Hz_Sts_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[24] = Suite_0;
                            RAFT_Resp_Result_u8[25] = TestCase_8;
                            RAFT_Resp_Result_u8[26] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[24] = Suite_0;
                            RAFT_Resp_Result_u8[25] = TestCase_8;
                            RAFT_Resp_Result_u8[26] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_9: 
                        Fas_Sts_VehStsSpdLo_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Sts_VehStaty_AlvCtr_Asmc_100Hz_Sts_VehStaty_AlvCtr();
                        if (Fas_Sts_VehStsSpdLo_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[27] = Suite_0;
                            RAFT_Resp_Result_u8[28] = TestCase_9;
                            RAFT_Resp_Result_u8[29] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[27] = Suite_0;
                            RAFT_Resp_Result_u8[28] = TestCase_9;
                            RAFT_Resp_Result_u8[29] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_10: 
                        Fas_Sts_VehStsSpdLo_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Sts_VehStaty_AlvCtr_Asmc_100Hz_Sts_VehStaty_AlvCtr();
                        if (Fas_Sts_VehStsSpdLo_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[30] = Suite_0;
                            RAFT_Resp_Result_u8[31] = TestCase_10;
                            RAFT_Resp_Result_u8[32] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[30] = Suite_0;
                            RAFT_Resp_Result_u8[31] = TestCase_10;
                            RAFT_Resp_Result_u8[32] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_11: 
                        Fas_Sts_VehStsSpdLo_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Sts_VehStaty_AlvCtr_Asmc_100Hz_Sts_VehStaty_AlvCtr();
                        if (Fas_Sts_VehStsSpdLo_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[33] = Suite_0;
                            RAFT_Resp_Result_u8[34] = TestCase_11;
                            RAFT_Resp_Result_u8[35] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[33] = Suite_0;
                            RAFT_Resp_Result_u8[34] = TestCase_11;
                            RAFT_Resp_Result_u8[35] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_12: 
                        Fas_Sts_VehSpdLo_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Sts_VehStaty_Crc_Asmc_100Hz_Sts_VehStaty_Crc();
                        if (Fas_Sts_VehSpdLo_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[36] = Suite_0;
                            RAFT_Resp_Result_u8[37] = TestCase_12;
                            RAFT_Resp_Result_u8[38] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[36] = Suite_0;
                            RAFT_Resp_Result_u8[37] = TestCase_12;
                            RAFT_Resp_Result_u8[38] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_13: 
                        Fas_Sts_VehSpdLo_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Sts_VehStaty_Crc_Asmc_100Hz_Sts_VehStaty_Crc();
                        if (Fas_Sts_VehSpdLo_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[39] = Suite_0;
                            RAFT_Resp_Result_u8[40] = TestCase_13;
                            RAFT_Resp_Result_u8[41] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[39] = Suite_0;
                            RAFT_Resp_Result_u8[40] = TestCase_13;
                            RAFT_Resp_Result_u8[41] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_14: 
                        Fas_Sts_VehSpdLo_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Sts_VehStaty_Crc_Asmc_100Hz_Sts_VehStaty_Crc();
                        if (Fas_Sts_VehSpdLo_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[42] = Suite_0;
                            RAFT_Resp_Result_u8[43] = TestCase_14;
                            RAFT_Resp_Result_u8[44] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[42] = Suite_0;
                            RAFT_Resp_Result_u8[43] = TestCase_14;
                            RAFT_Resp_Result_u8[44] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_15: 
                        Fas_Sts_VehStsStaty_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Zl_Mofr_AlvCtr_Asmc_100Hz_Zl_Mofr_AlvCtr();
                        if (Fas_Sts_VehStsStaty_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[45] = Suite_0;
                            RAFT_Resp_Result_u8[46] = TestCase_15;
                            RAFT_Resp_Result_u8[47] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[45] = Suite_0;
                            RAFT_Resp_Result_u8[46] = TestCase_15;
                            RAFT_Resp_Result_u8[47] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_16: 
                        Fas_Sts_VehStsStaty_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Zl_Mofr_AlvCtr_Asmc_100Hz_Zl_Mofr_AlvCtr();
                        if (Fas_Sts_VehStsStaty_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[48] = Suite_0;
                            RAFT_Resp_Result_u8[49] = TestCase_16;
                            RAFT_Resp_Result_u8[50] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[48] = Suite_0;
                            RAFT_Resp_Result_u8[49] = TestCase_16;
                            RAFT_Resp_Result_u8[50] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_17: 
                        Fas_Sts_VehStsStaty_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Zl_Mofr_AlvCtr_Asmc_100Hz_Zl_Mofr_AlvCtr();
                        if (Fas_Sts_VehStsStaty_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[51] = Suite_0;
                            RAFT_Resp_Result_u8[52] = TestCase_17;
                            RAFT_Resp_Result_u8[53] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[51] = Suite_0;
                            RAFT_Resp_Result_u8[52] = TestCase_17;
                            RAFT_Resp_Result_u8[53] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_18: 
                        Fas_Sts_VehStaty_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_25Hz_Sts_AlvCtr_Asmc_25Hz_Sts_AlvCtr();
                        if (Fas_Sts_VehStaty_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[54] = Suite_0;
                            RAFT_Resp_Result_u8[55] = TestCase_18;
                            RAFT_Resp_Result_u8[56] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[54] = Suite_0;
                            RAFT_Resp_Result_u8[55] = TestCase_18;
                            RAFT_Resp_Result_u8[56] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_19: 
                        Fas_Sts_VehStaty_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_25Hz_Sts_AlvCtr_Asmc_25Hz_Sts_AlvCtr();
                        if (Fas_Sts_VehStaty_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[57] = Suite_0;
                            RAFT_Resp_Result_u8[58] = TestCase_19;
                            RAFT_Resp_Result_u8[59] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[57] = Suite_0;
                            RAFT_Resp_Result_u8[58] = TestCase_19;
                            RAFT_Resp_Result_u8[59] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_20: 
                        Fas_Sts_VehStaty_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_25Hz_Sts_AlvCtr_Asmc_25Hz_Sts_AlvCtr();
                        if (Fas_Sts_VehStaty_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[60] = Suite_0;
                            RAFT_Resp_Result_u8[61] = TestCase_20;
                            RAFT_Resp_Result_u8[62] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[60] = Suite_0;
                            RAFT_Resp_Result_u8[61] = TestCase_20;
                            RAFT_Resp_Result_u8[62] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_21: 
                        Asmc_100Hz_Sts_VehStaty_Crc_sig = Rte_IRead_RAFT_SWC_Main_Asmc_Req_DaHlthTest_Na_Asmc_Req_DaHlthTest_Na();
                        if (Asmc_100Hz_Sts_VehStaty_Crc_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[63] = Suite_0;
                            RAFT_Resp_Result_u8[64] = TestCase_21;
                            RAFT_Resp_Result_u8[65] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[63] = Suite_0;
                            RAFT_Resp_Result_u8[64] = TestCase_21;
                            RAFT_Resp_Result_u8[65] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_22: 
                        Asmc_100Hz_Sts_VehStaty_Crc_sig = Rte_IRead_RAFT_SWC_Main_Asmc_Req_DaHlthTest_Na_Asmc_Req_DaHlthTest_Na();
                        if (Asmc_100Hz_Sts_VehStaty_Crc_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[66] = Suite_0;
                            RAFT_Resp_Result_u8[67] = TestCase_22;
                            RAFT_Resp_Result_u8[68] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[66] = Suite_0;
                            RAFT_Resp_Result_u8[67] = TestCase_22;
                            RAFT_Resp_Result_u8[68] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_23: 
                        Asmc_100Hz_Sts_VehStaty_Crc_sig = Rte_IRead_RAFT_SWC_Main_Asmc_Req_DaHlthTest_Na_Asmc_Req_DaHlthTest_Na();
                        if (Asmc_100Hz_Sts_VehStaty_Crc_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[69] = Suite_0;
                            RAFT_Resp_Result_u8[70] = TestCase_23;
                            RAFT_Resp_Result_u8[71] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[69] = Suite_0;
                            RAFT_Resp_Result_u8[70] = TestCase_23;
                            RAFT_Resp_Result_u8[71] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_24: 
                        Asmc_100Hz_Sts_VehStaty_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Fl_AtActr_Cmd_Nwt_Faa_F_Fl_AtActr_Cmd_Nwt();
                        if (Asmc_100Hz_Sts_VehStaty_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[72] = Suite_0;
                            RAFT_Resp_Result_u8[73] = TestCase_24;
                            RAFT_Resp_Result_u8[74] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[72] = Suite_0;
                            RAFT_Resp_Result_u8[73] = TestCase_24;
                            RAFT_Resp_Result_u8[74] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_25: 
                        Asmc_100Hz_Sts_VehStaty_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Fl_AtActr_Cmd_Nwt_Faa_F_Fl_AtActr_Cmd_Nwt();
                        if (Asmc_100Hz_Sts_VehStaty_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[75] = Suite_0;
                            RAFT_Resp_Result_u8[76] = TestCase_25;
                            RAFT_Resp_Result_u8[77] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[75] = Suite_0;
                            RAFT_Resp_Result_u8[76] = TestCase_25;
                            RAFT_Resp_Result_u8[77] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_26: 
                        Asmc_100Hz_Sts_VehStaty_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Fl_AtActr_Cmd_Nwt_Faa_F_Fl_AtActr_Cmd_Nwt();
                        if (Asmc_100Hz_Sts_VehStaty_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[78] = Suite_0;
                            RAFT_Resp_Result_u8[79] = TestCase_26;
                            RAFT_Resp_Result_u8[80] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[78] = Suite_0;
                            RAFT_Resp_Result_u8[79] = TestCase_26;
                            RAFT_Resp_Result_u8[80] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_27: 
                        Faa_Sts_F_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Fr_AtActr_Cmd_Nwt_Faa_F_Fr_AtActr_Cmd_Nwt();
                        if (Faa_Sts_F_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[81] = Suite_0;
                            RAFT_Resp_Result_u8[82] = TestCase_27;
                            RAFT_Resp_Result_u8[83] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[81] = Suite_0;
                            RAFT_Resp_Result_u8[82] = TestCase_27;
                            RAFT_Resp_Result_u8[83] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_28: 
                        Faa_Sts_F_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Fr_AtActr_Cmd_Nwt_Faa_F_Fr_AtActr_Cmd_Nwt();
                        if (Faa_Sts_F_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[84] = Suite_0;
                            RAFT_Resp_Result_u8[85] = TestCase_28;
                            RAFT_Resp_Result_u8[86] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[84] = Suite_0;
                            RAFT_Resp_Result_u8[85] = TestCase_28;
                            RAFT_Resp_Result_u8[86] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_29: 
                        Faa_Sts_F_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Fr_AtActr_Cmd_Nwt_Faa_F_Fr_AtActr_Cmd_Nwt();
                        if (Faa_Sts_F_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[87] = Suite_0;
                            RAFT_Resp_Result_u8[88] = TestCase_29;
                            RAFT_Resp_Result_u8[89] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[87] = Suite_0;
                            RAFT_Resp_Result_u8[88] = TestCase_29;
                            RAFT_Resp_Result_u8[89] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_30: 
                        Faa_F_Rr_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Rl_AtActr_Cmd_Nwt_Faa_F_Rl_AtActr_Cmd_Nwt();
                        if (Faa_F_Rr_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[90] = Suite_0;
                            RAFT_Resp_Result_u8[91] = TestCase_30;
                            RAFT_Resp_Result_u8[92] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[90] = Suite_0;
                            RAFT_Resp_Result_u8[91] = TestCase_30;
                            RAFT_Resp_Result_u8[92] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_31: 
                        Faa_F_Rr_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Rl_AtActr_Cmd_Nwt_Faa_F_Rl_AtActr_Cmd_Nwt();
                        if (Faa_F_Rr_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[93] = Suite_0;
                            RAFT_Resp_Result_u8[94] = TestCase_31;
                            RAFT_Resp_Result_u8[95] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[93] = Suite_0;
                            RAFT_Resp_Result_u8[94] = TestCase_31;
                            RAFT_Resp_Result_u8[95] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_32: 
                        Faa_F_Rr_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Rl_AtActr_Cmd_Nwt_Faa_F_Rl_AtActr_Cmd_Nwt();
                        if (Faa_F_Rr_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[96] = Suite_0;
                            RAFT_Resp_Result_u8[97] = TestCase_32;
                            RAFT_Resp_Result_u8[98] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[96] = Suite_0;
                            RAFT_Resp_Result_u8[97] = TestCase_32;
                            RAFT_Resp_Result_u8[98] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_33: 
                        Faa_F_Rl_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Rr_AtActr_Cmd_Nwt_Faa_F_Rr_AtActr_Cmd_Nwt();
                        if (Faa_F_Rl_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[99] = Suite_0;
                            RAFT_Resp_Result_u8[100] = TestCase_33;
                            RAFT_Resp_Result_u8[101] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[99] = Suite_0;
                            RAFT_Resp_Result_u8[100] = TestCase_33;
                            RAFT_Resp_Result_u8[101] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_34: 
                        Faa_F_Rl_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Rr_AtActr_Cmd_Nwt_Faa_F_Rr_AtActr_Cmd_Nwt();
                        if (Faa_F_Rl_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[102] = Suite_0;
                            RAFT_Resp_Result_u8[103] = TestCase_34;
                            RAFT_Resp_Result_u8[104] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[102] = Suite_0;
                            RAFT_Resp_Result_u8[103] = TestCase_34;
                            RAFT_Resp_Result_u8[104] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_35: 
                        Faa_F_Rl_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Rr_AtActr_Cmd_Nwt_Faa_F_Rr_AtActr_Cmd_Nwt();
                        if (Faa_F_Rl_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[105] = Suite_0;
                            RAFT_Resp_Result_u8[106] = TestCase_35;
                            RAFT_Resp_Result_u8[107] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[105] = Suite_0;
                            RAFT_Resp_Result_u8[106] = TestCase_35;
                            RAFT_Resp_Result_u8[107] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_36: 
                        Faa_F_Fr_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_Frq_Fn_ZlFil_Ce_Hz_Faa_Frq_Fn_ZlFil_Ce_Hz();
                        if (Faa_F_Fr_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[108] = Suite_0;
                            RAFT_Resp_Result_u8[109] = TestCase_36;
                            RAFT_Resp_Result_u8[110] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[108] = Suite_0;
                            RAFT_Resp_Result_u8[109] = TestCase_36;
                            RAFT_Resp_Result_u8[110] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_37: 
                        Faa_F_Fr_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_Frq_Fn_ZlFil_Ce_Hz_Faa_Frq_Fn_ZlFil_Ce_Hz();
                        if (Faa_F_Fr_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[111] = Suite_0;
                            RAFT_Resp_Result_u8[112] = TestCase_37;
                            RAFT_Resp_Result_u8[113] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[111] = Suite_0;
                            RAFT_Resp_Result_u8[112] = TestCase_37;
                            RAFT_Resp_Result_u8[113] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_38: 
                        Faa_F_Fr_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_Frq_Fn_ZlFil_Ce_Hz_Faa_Frq_Fn_ZlFil_Ce_Hz();
                        if (Faa_F_Fr_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[114] = Suite_0;
                            RAFT_Resp_Result_u8[115] = TestCase_38;
                            RAFT_Resp_Result_u8[116] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[114] = Suite_0;
                            RAFT_Resp_Result_u8[115] = TestCase_38;
                            RAFT_Resp_Result_u8[116] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_39: 
                        Faa_F_Fl_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_Frq_Re_ZlFil_Ce_Hz_Faa_Frq_Re_ZlFil_Ce_Hz();
                        if (Faa_F_Fl_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[117] = Suite_0;
                            RAFT_Resp_Result_u8[118] = TestCase_39;
                            RAFT_Resp_Result_u8[119] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[117] = Suite_0;
                            RAFT_Resp_Result_u8[118] = TestCase_39;
                            RAFT_Resp_Result_u8[119] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_40: 
                        Faa_F_Fl_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_Frq_Re_ZlFil_Ce_Hz_Faa_Frq_Re_ZlFil_Ce_Hz();
                        if (Faa_F_Fl_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[120] = Suite_0;
                            RAFT_Resp_Result_u8[121] = TestCase_40;
                            RAFT_Resp_Result_u8[122] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[120] = Suite_0;
                            RAFT_Resp_Result_u8[121] = TestCase_40;
                            RAFT_Resp_Result_u8[122] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_41: 
                        Faa_F_Fl_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_Frq_Re_ZlFil_Ce_Hz_Faa_Frq_Re_ZlFil_Ce_Hz();
                        if (Faa_F_Fl_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[123] = Suite_0;
                            RAFT_Resp_Result_u8[124] = TestCase_41;
                            RAFT_Resp_Result_u8[125] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[123] = Suite_0;
                            RAFT_Resp_Result_u8[124] = TestCase_41;
                            RAFT_Resp_Result_u8[125] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_42: 
                        Asmc_1000Hz_F_Cmd_Crc_sig = Rte_IRead_RAFT_SWC_Main_Faa_Gain_Fn_ZlFil_Na_Faa_Gain_Fn_ZlFil_Na();
                        if (Asmc_1000Hz_F_Cmd_Crc_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[126] = Suite_0;
                            RAFT_Resp_Result_u8[127] = TestCase_42;
                            RAFT_Resp_Result_u8[128] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[126] = Suite_0;
                            RAFT_Resp_Result_u8[127] = TestCase_42;
                            RAFT_Resp_Result_u8[128] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_43: 
                        Asmc_1000Hz_F_Cmd_Crc_sig = Rte_IRead_RAFT_SWC_Main_Faa_Gain_Fn_ZlFil_Na_Faa_Gain_Fn_ZlFil_Na();
                        if (Asmc_1000Hz_F_Cmd_Crc_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[129] = Suite_0;
                            RAFT_Resp_Result_u8[130] = TestCase_43;
                            RAFT_Resp_Result_u8[131] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[129] = Suite_0;
                            RAFT_Resp_Result_u8[130] = TestCase_43;
                            RAFT_Resp_Result_u8[131] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_44: 
                        Asmc_1000Hz_F_Cmd_Crc_sig = Rte_IRead_RAFT_SWC_Main_Faa_Gain_Fn_ZlFil_Na_Faa_Gain_Fn_ZlFil_Na();
                        if (Asmc_1000Hz_F_Cmd_Crc_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[132] = Suite_0;
                            RAFT_Resp_Result_u8[133] = TestCase_44;
                            RAFT_Resp_Result_u8[134] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[132] = Suite_0;
                            RAFT_Resp_Result_u8[133] = TestCase_44;
                            RAFT_Resp_Result_u8[134] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_45: 
                        Asmc_1000Hz_F_Cmd_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Faa_Gain_Re_ZlFil_Na_Faa_Gain_Re_ZlFil_Na();
                        if (Asmc_1000Hz_F_Cmd_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[135] = Suite_0;
                            RAFT_Resp_Result_u8[136] = TestCase_45;
                            RAFT_Resp_Result_u8[137] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[135] = Suite_0;
                            RAFT_Resp_Result_u8[136] = TestCase_45;
                            RAFT_Resp_Result_u8[137] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_46: 
                        Asmc_1000Hz_F_Cmd_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Faa_Gain_Re_ZlFil_Na_Faa_Gain_Re_ZlFil_Na();
                        if (Asmc_1000Hz_F_Cmd_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[138] = Suite_0;
                            RAFT_Resp_Result_u8[139] = TestCase_46;
                            RAFT_Resp_Result_u8[140] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[138] = Suite_0;
                            RAFT_Resp_Result_u8[139] = TestCase_46;
                            RAFT_Resp_Result_u8[140] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_47: 
                        Asmc_1000Hz_F_Cmd_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Faa_Gain_Re_ZlFil_Na_Faa_Gain_Re_ZlFil_Na();
                        if (Asmc_1000Hz_F_Cmd_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[141] = Suite_0;
                            RAFT_Resp_Result_u8[142] = TestCase_47;
                            RAFT_Resp_Result_u8[143] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[141] = Suite_0;
                            RAFT_Resp_Result_u8[142] = TestCase_47;
                            RAFT_Resp_Result_u8[143] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_48: 
                        Faa_Sts_ZlMofr_Re_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Mofr_Fn_ZlGain_Na_Faa_Mofr_Fn_ZlGain_Na();
                        if (Faa_Sts_ZlMofr_Re_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[144] = Suite_0;
                            RAFT_Resp_Result_u8[145] = TestCase_48;
                            RAFT_Resp_Result_u8[146] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[144] = Suite_0;
                            RAFT_Resp_Result_u8[145] = TestCase_48;
                            RAFT_Resp_Result_u8[146] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_49: 
                        Faa_Sts_ZlMofr_Re_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Mofr_Fn_ZlGain_Na_Faa_Mofr_Fn_ZlGain_Na();
                        if (Faa_Sts_ZlMofr_Re_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[147] = Suite_0;
                            RAFT_Resp_Result_u8[148] = TestCase_49;
                            RAFT_Resp_Result_u8[149] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[147] = Suite_0;
                            RAFT_Resp_Result_u8[148] = TestCase_49;
                            RAFT_Resp_Result_u8[149] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_50: 
                        Faa_Sts_ZlMofr_Re_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Mofr_Fn_ZlGain_Na_Faa_Mofr_Fn_ZlGain_Na();
                        if (Faa_Sts_ZlMofr_Re_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[150] = Suite_0;
                            RAFT_Resp_Result_u8[151] = TestCase_50;
                            RAFT_Resp_Result_u8[152] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[150] = Suite_0;
                            RAFT_Resp_Result_u8[151] = TestCase_50;
                            RAFT_Resp_Result_u8[152] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_51: 
                        Faa_Gain_Re_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Mofr_Re_ZlGain_Na_Faa_Mofr_Re_ZlGain_Na();
                        if (Faa_Gain_Re_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[153] = Suite_0;
                            RAFT_Resp_Result_u8[154] = TestCase_51;
                            RAFT_Resp_Result_u8[155] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[153] = Suite_0;
                            RAFT_Resp_Result_u8[154] = TestCase_51;
                            RAFT_Resp_Result_u8[155] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_52: 
                        Faa_Gain_Re_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Mofr_Re_ZlGain_Na_Faa_Mofr_Re_ZlGain_Na();
                        if (Faa_Gain_Re_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[156] = Suite_0;
                            RAFT_Resp_Result_u8[157] = TestCase_52;
                            RAFT_Resp_Result_u8[158] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[156] = Suite_0;
                            RAFT_Resp_Result_u8[157] = TestCase_52;
                            RAFT_Resp_Result_u8[158] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_53: 
                        Faa_Gain_Re_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Mofr_Re_ZlGain_Na_Faa_Mofr_Re_ZlGain_Na();
                        if (Faa_Gain_Re_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[159] = Suite_0;
                            RAFT_Resp_Result_u8[160] = TestCase_53;
                            RAFT_Resp_Result_u8[161] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[159] = Suite_0;
                            RAFT_Resp_Result_u8[160] = TestCase_53;
                            RAFT_Resp_Result_u8[161] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_54: 
                        Faa_Wi_Re_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Sts_F_Qfr_Na_Faa_Sts_F_Qfr_Na();
                        if (Faa_Wi_Re_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[162] = Suite_0;
                            RAFT_Resp_Result_u8[163] = TestCase_54;
                            RAFT_Resp_Result_u8[164] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[162] = Suite_0;
                            RAFT_Resp_Result_u8[163] = TestCase_54;
                            RAFT_Resp_Result_u8[164] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_55: 
                        Faa_Wi_Re_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Sts_F_Qfr_Na_Faa_Sts_F_Qfr_Na();
                        if (Faa_Wi_Re_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[165] = Suite_0;
                            RAFT_Resp_Result_u8[166] = TestCase_55;
                            RAFT_Resp_Result_u8[167] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[165] = Suite_0;
                            RAFT_Resp_Result_u8[166] = TestCase_55;
                            RAFT_Resp_Result_u8[167] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_56: 
                        Faa_Wi_Re_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Sts_F_Qfr_Na_Faa_Sts_F_Qfr_Na();
                        if (Faa_Wi_Re_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[168] = Suite_0;
                            RAFT_Resp_Result_u8[169] = TestCase_56;
                            RAFT_Resp_Result_u8[170] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[168] = Suite_0;
                            RAFT_Resp_Result_u8[169] = TestCase_56;
                            RAFT_Resp_Result_u8[170] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_57: 
                        Faa_Frq_Re_ZlFil_Ce_Hz_sig = Rte_IRead_RAFT_SWC_Main_Faa_Sts_ZlMofr_Fn_Qfr_Na_Faa_Sts_ZlMofr_Fn_Qfr_Na();
                        if (Faa_Frq_Re_ZlFil_Ce_Hz_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[171] = Suite_0;
                            RAFT_Resp_Result_u8[172] = TestCase_57;
                            RAFT_Resp_Result_u8[173] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[171] = Suite_0;
                            RAFT_Resp_Result_u8[172] = TestCase_57;
                            RAFT_Resp_Result_u8[173] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_58: 
                        Faa_Frq_Re_ZlFil_Ce_Hz_sig = Rte_IRead_RAFT_SWC_Main_Faa_Sts_ZlMofr_Fn_Qfr_Na_Faa_Sts_ZlMofr_Fn_Qfr_Na();
                        if (Faa_Frq_Re_ZlFil_Ce_Hz_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[174] = Suite_0;
                            RAFT_Resp_Result_u8[175] = TestCase_58;
                            RAFT_Resp_Result_u8[176] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[174] = Suite_0;
                            RAFT_Resp_Result_u8[175] = TestCase_58;
                            RAFT_Resp_Result_u8[176] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_59: 
                        Faa_Frq_Re_ZlFil_Ce_Hz_sig = Rte_IRead_RAFT_SWC_Main_Faa_Sts_ZlMofr_Fn_Qfr_Na_Faa_Sts_ZlMofr_Fn_Qfr_Na();
                        if (Faa_Frq_Re_ZlFil_Ce_Hz_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[177] = Suite_0;
                            RAFT_Resp_Result_u8[178] = TestCase_59;
                            RAFT_Resp_Result_u8[179] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[177] = Suite_0;
                            RAFT_Resp_Result_u8[178] = TestCase_59;
                            RAFT_Resp_Result_u8[179] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_60: 
                        Faa_Mofr_Re_ZlGain_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Sts_ZlMofr_Re_Qfr_Na_Faa_Sts_ZlMofr_Re_Qfr_Na();
                        if (Faa_Mofr_Re_ZlGain_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[180] = Suite_0;
                            RAFT_Resp_Result_u8[181] = TestCase_60;
                            RAFT_Resp_Result_u8[182] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[180] = Suite_0;
                            RAFT_Resp_Result_u8[181] = TestCase_60;
                            RAFT_Resp_Result_u8[182] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_61: 
                        Faa_Mofr_Re_ZlGain_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Sts_ZlMofr_Re_Qfr_Na_Faa_Sts_ZlMofr_Re_Qfr_Na();
                        if (Faa_Mofr_Re_ZlGain_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[183] = Suite_0;
                            RAFT_Resp_Result_u8[184] = TestCase_61;
                            RAFT_Resp_Result_u8[185] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[183] = Suite_0;
                            RAFT_Resp_Result_u8[184] = TestCase_61;
                            RAFT_Resp_Result_u8[185] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_62: 
                        Faa_Mofr_Re_ZlGain_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Sts_ZlMofr_Re_Qfr_Na_Faa_Sts_ZlMofr_Re_Qfr_Na();
                        if (Faa_Mofr_Re_ZlGain_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[186] = Suite_0;
                            RAFT_Resp_Result_u8[187] = TestCase_62;
                            RAFT_Resp_Result_u8[188] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[186] = Suite_0;
                            RAFT_Resp_Result_u8[187] = TestCase_62;
                            RAFT_Resp_Result_u8[188] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_63: 
                        Faa_Sts_ZlMofr_Fn_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Wi_Fn_ZlFil_Na_Faa_Wi_Fn_ZlFil_Na();
                        if (Faa_Sts_ZlMofr_Fn_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[189] = Suite_0;
                            RAFT_Resp_Result_u8[190] = TestCase_63;
                            RAFT_Resp_Result_u8[191] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[189] = Suite_0;
                            RAFT_Resp_Result_u8[190] = TestCase_63;
                            RAFT_Resp_Result_u8[191] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_64: 
                        Faa_Sts_ZlMofr_Fn_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Wi_Fn_ZlFil_Na_Faa_Wi_Fn_ZlFil_Na();
                        if (Faa_Sts_ZlMofr_Fn_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[192] = Suite_0;
                            RAFT_Resp_Result_u8[193] = TestCase_64;
                            RAFT_Resp_Result_u8[194] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[192] = Suite_0;
                            RAFT_Resp_Result_u8[193] = TestCase_64;
                            RAFT_Resp_Result_u8[194] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_65: 
                        Faa_Sts_ZlMofr_Fn_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Wi_Fn_ZlFil_Na_Faa_Wi_Fn_ZlFil_Na();
                        if (Faa_Sts_ZlMofr_Fn_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[195] = Suite_0;
                            RAFT_Resp_Result_u8[196] = TestCase_65;
                            RAFT_Resp_Result_u8[197] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[195] = Suite_0;
                            RAFT_Resp_Result_u8[196] = TestCase_65;
                            RAFT_Resp_Result_u8[197] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_66: 
                        Faa_Gain_Fn_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Wi_Re_ZlFil_Na_Faa_Wi_Re_ZlFil_Na();
                        if (Faa_Gain_Fn_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[198] = Suite_0;
                            RAFT_Resp_Result_u8[199] = TestCase_66;
                            RAFT_Resp_Result_u8[200] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[198] = Suite_0;
                            RAFT_Resp_Result_u8[199] = TestCase_66;
                            RAFT_Resp_Result_u8[200] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_67: 
                        Faa_Gain_Fn_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Wi_Re_ZlFil_Na_Faa_Wi_Re_ZlFil_Na();
                        if (Faa_Gain_Fn_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[201] = Suite_0;
                            RAFT_Resp_Result_u8[202] = TestCase_67;
                            RAFT_Resp_Result_u8[203] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[201] = Suite_0;
                            RAFT_Resp_Result_u8[202] = TestCase_67;
                            RAFT_Resp_Result_u8[203] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_68: 
                        Faa_Gain_Fn_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Wi_Re_ZlFil_Na_Faa_Wi_Re_ZlFil_Na();
                        if (Faa_Gain_Fn_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[204] = Suite_0;
                            RAFT_Resp_Result_u8[205] = TestCase_68;
                            RAFT_Resp_Result_u8[206] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[204] = Suite_0;
                            RAFT_Resp_Result_u8[205] = TestCase_68;
                            RAFT_Resp_Result_u8[206] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_69: 
                        Faa_Wi_Fn_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehSpdLo_Na_Fas_Sts_VehSpdLo_Na();
                        if (Faa_Wi_Fn_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[207] = Suite_0;
                            RAFT_Resp_Result_u8[208] = TestCase_69;
                            RAFT_Resp_Result_u8[209] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[207] = Suite_0;
                            RAFT_Resp_Result_u8[208] = TestCase_69;
                            RAFT_Resp_Result_u8[209] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_70: 
                        Faa_Wi_Fn_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehSpdLo_Na_Fas_Sts_VehSpdLo_Na();
                        if (Faa_Wi_Fn_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[210] = Suite_0;
                            RAFT_Resp_Result_u8[211] = TestCase_70;
                            RAFT_Resp_Result_u8[212] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[210] = Suite_0;
                            RAFT_Resp_Result_u8[211] = TestCase_70;
                            RAFT_Resp_Result_u8[212] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_71: 
                        Faa_Wi_Fn_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehSpdLo_Na_Fas_Sts_VehSpdLo_Na();
                        if (Faa_Wi_Fn_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[213] = Suite_0;
                            RAFT_Resp_Result_u8[214] = TestCase_71;
                            RAFT_Resp_Result_u8[215] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[213] = Suite_0;
                            RAFT_Resp_Result_u8[214] = TestCase_71;
                            RAFT_Resp_Result_u8[215] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_72: 
                        Faa_Frq_Fn_ZlFil_Ce_Hz_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStaty_Na_Fas_Sts_VehStaty_Na();
                        if (Faa_Frq_Fn_ZlFil_Ce_Hz_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[216] = Suite_0;
                            RAFT_Resp_Result_u8[217] = TestCase_72;
                            RAFT_Resp_Result_u8[218] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[216] = Suite_0;
                            RAFT_Resp_Result_u8[217] = TestCase_72;
                            RAFT_Resp_Result_u8[218] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_73: 
                        Faa_Frq_Fn_ZlFil_Ce_Hz_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStaty_Na_Fas_Sts_VehStaty_Na();
                        if (Faa_Frq_Fn_ZlFil_Ce_Hz_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[219] = Suite_0;
                            RAFT_Resp_Result_u8[220] = TestCase_73;
                            RAFT_Resp_Result_u8[221] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[219] = Suite_0;
                            RAFT_Resp_Result_u8[220] = TestCase_73;
                            RAFT_Resp_Result_u8[221] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_74: 
                        Faa_Frq_Fn_ZlFil_Ce_Hz_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStaty_Na_Fas_Sts_VehStaty_Na();
                        if (Faa_Frq_Fn_ZlFil_Ce_Hz_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[222] = Suite_0;
                            RAFT_Resp_Result_u8[223] = TestCase_74;
                            RAFT_Resp_Result_u8[224] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[222] = Suite_0;
                            RAFT_Resp_Result_u8[223] = TestCase_74;
                            RAFT_Resp_Result_u8[224] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_75: 
                        Faa_Mofr_Fn_ZlGain_Na_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStsSpdLo_Qfr_Na_Fas_Sts_VehStsSpdLo_Qfr_Na();
                        if (Faa_Mofr_Fn_ZlGain_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[225] = Suite_0;
                            RAFT_Resp_Result_u8[226] = TestCase_75;
                            RAFT_Resp_Result_u8[227] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[225] = Suite_0;
                            RAFT_Resp_Result_u8[226] = TestCase_75;
                            RAFT_Resp_Result_u8[227] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_76: 
                        Faa_Mofr_Fn_ZlGain_Na_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStsSpdLo_Qfr_Na_Fas_Sts_VehStsSpdLo_Qfr_Na();
                        if (Faa_Mofr_Fn_ZlGain_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[228] = Suite_0;
                            RAFT_Resp_Result_u8[229] = TestCase_76;
                            RAFT_Resp_Result_u8[230] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[228] = Suite_0;
                            RAFT_Resp_Result_u8[229] = TestCase_76;
                            RAFT_Resp_Result_u8[230] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_77: 
                        Faa_Mofr_Fn_ZlGain_Na_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStsSpdLo_Qfr_Na_Fas_Sts_VehStsSpdLo_Qfr_Na();
                        if (Faa_Mofr_Fn_ZlGain_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[231] = Suite_0;
                            RAFT_Resp_Result_u8[232] = TestCase_77;
                            RAFT_Resp_Result_u8[233] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[231] = Suite_0;
                            RAFT_Resp_Result_u8[232] = TestCase_77;
                            RAFT_Resp_Result_u8[233] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_78: 
                        Asmc_100Hz_Zl_Mofr_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStsStaty_Qfr_Na_Fas_Sts_VehStsStaty_Qfr_Na();
                        if (Asmc_100Hz_Zl_Mofr_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[234] = Suite_0;
                            RAFT_Resp_Result_u8[235] = TestCase_78;
                            RAFT_Resp_Result_u8[236] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[234] = Suite_0;
                            RAFT_Resp_Result_u8[235] = TestCase_78;
                            RAFT_Resp_Result_u8[236] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_79: 
                        Asmc_100Hz_Zl_Mofr_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStsStaty_Qfr_Na_Fas_Sts_VehStsStaty_Qfr_Na();
                        if (Asmc_100Hz_Zl_Mofr_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[237] = Suite_0;
                            RAFT_Resp_Result_u8[238] = TestCase_79;
                            RAFT_Resp_Result_u8[239] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[237] = Suite_0;
                            RAFT_Resp_Result_u8[238] = TestCase_79;
                            RAFT_Resp_Result_u8[239] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_80: 
                        Asmc_100Hz_Zl_Mofr_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStsStaty_Qfr_Na_Fas_Sts_VehStsStaty_Qfr_Na();
                        if (Asmc_100Hz_Zl_Mofr_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[240] = Suite_0;
                            RAFT_Resp_Result_u8[241] = TestCase_80;
                            RAFT_Resp_Result_u8[242] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[240] = Suite_0;
                            RAFT_Resp_Result_u8[241] = TestCase_80;
                            RAFT_Resp_Result_u8[242] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                }
            break; 
    
            case Suite_1: 
                switch (Data[1])
                { 
    
                    case TestCase_0: 
                        Asmc_Req_DaHlthTest_Na_sig = Rte_IRead_RAFT_SWC_Main_Ascc_St_Req_Na_Ascc_St_Req_Na();
                        if (Asmc_Req_DaHlthTest_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[243] = Suite_1;
                            RAFT_Resp_Result_u8[244] = TestCase_0;
                            RAFT_Resp_Result_u8[245] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[243] = Suite_1;
                            RAFT_Resp_Result_u8[244] = TestCase_0;
                            RAFT_Resp_Result_u8[245] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_1: 
                        Ascc_St_Req_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_1000Hz_F_Cmd_AlvCtr_Asmc_1000Hz_F_Cmd_AlvCtr();
                        if (Ascc_St_Req_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[246] = Suite_1;
                            RAFT_Resp_Result_u8[247] = TestCase_1;
                            RAFT_Resp_Result_u8[248] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[246] = Suite_1;
                            RAFT_Resp_Result_u8[247] = TestCase_1;
                            RAFT_Resp_Result_u8[248] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_2: 
                        Asmc_25Hz_Sts_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Asmc_1000Hz_F_Cmd_Crc_Asmc_1000Hz_F_Cmd_Crc();
                        if (Asmc_25Hz_Sts_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[249] = Suite_1;
                            RAFT_Resp_Result_u8[250] = TestCase_2;
                            RAFT_Resp_Result_u8[251] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[249] = Suite_1;
                            RAFT_Resp_Result_u8[250] = TestCase_2;
                            RAFT_Resp_Result_u8[251] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_3: 
                        Fas_Sts_VehStsSpdLo_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Sts_VehStaty_AlvCtr_Asmc_100Hz_Sts_VehStaty_AlvCtr();
                        if (Fas_Sts_VehStsSpdLo_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[252] = Suite_1;
                            RAFT_Resp_Result_u8[253] = TestCase_3;
                            RAFT_Resp_Result_u8[254] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[252] = Suite_1;
                            RAFT_Resp_Result_u8[253] = TestCase_3;
                            RAFT_Resp_Result_u8[254] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_4: 
                        Fas_Sts_VehSpdLo_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Sts_VehStaty_Crc_Asmc_100Hz_Sts_VehStaty_Crc();
                        if (Fas_Sts_VehSpdLo_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[255] = Suite_1;
                            RAFT_Resp_Result_u8[256] = TestCase_4;
                            RAFT_Resp_Result_u8[257] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[255] = Suite_1;
                            RAFT_Resp_Result_u8[256] = TestCase_4;
                            RAFT_Resp_Result_u8[257] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_5: 
                        Fas_Sts_VehStsStaty_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Zl_Mofr_AlvCtr_Asmc_100Hz_Zl_Mofr_AlvCtr();
                        if (Fas_Sts_VehStsStaty_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[258] = Suite_1;
                            RAFT_Resp_Result_u8[259] = TestCase_5;
                            RAFT_Resp_Result_u8[260] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[258] = Suite_1;
                            RAFT_Resp_Result_u8[259] = TestCase_5;
                            RAFT_Resp_Result_u8[260] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_6: 
                        Fas_Sts_VehStaty_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_25Hz_Sts_AlvCtr_Asmc_25Hz_Sts_AlvCtr();
                        if (Fas_Sts_VehStaty_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[261] = Suite_1;
                            RAFT_Resp_Result_u8[262] = TestCase_6;
                            RAFT_Resp_Result_u8[263] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[261] = Suite_1;
                            RAFT_Resp_Result_u8[262] = TestCase_6;
                            RAFT_Resp_Result_u8[263] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_7: 
                        Asmc_100Hz_Sts_VehStaty_Crc_sig = Rte_IRead_RAFT_SWC_Main_Asmc_Req_DaHlthTest_Na_Asmc_Req_DaHlthTest_Na();
                        if (Asmc_100Hz_Sts_VehStaty_Crc_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[264] = Suite_1;
                            RAFT_Resp_Result_u8[265] = TestCase_7;
                            RAFT_Resp_Result_u8[266] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[264] = Suite_1;
                            RAFT_Resp_Result_u8[265] = TestCase_7;
                            RAFT_Resp_Result_u8[266] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_8: 
                        Asmc_100Hz_Sts_VehStaty_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Fl_AtActr_Cmd_Nwt_Faa_F_Fl_AtActr_Cmd_Nwt();
                        if (Asmc_100Hz_Sts_VehStaty_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[267] = Suite_1;
                            RAFT_Resp_Result_u8[268] = TestCase_8;
                            RAFT_Resp_Result_u8[269] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[267] = Suite_1;
                            RAFT_Resp_Result_u8[268] = TestCase_8;
                            RAFT_Resp_Result_u8[269] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_9: 
                        Faa_Sts_F_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Fr_AtActr_Cmd_Nwt_Faa_F_Fr_AtActr_Cmd_Nwt();
                        if (Faa_Sts_F_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[270] = Suite_1;
                            RAFT_Resp_Result_u8[271] = TestCase_9;
                            RAFT_Resp_Result_u8[272] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[270] = Suite_1;
                            RAFT_Resp_Result_u8[271] = TestCase_9;
                            RAFT_Resp_Result_u8[272] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_10: 
                        Faa_F_Rr_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Rl_AtActr_Cmd_Nwt_Faa_F_Rl_AtActr_Cmd_Nwt();
                        if (Faa_F_Rr_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[273] = Suite_1;
                            RAFT_Resp_Result_u8[274] = TestCase_10;
                            RAFT_Resp_Result_u8[275] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[273] = Suite_1;
                            RAFT_Resp_Result_u8[274] = TestCase_10;
                            RAFT_Resp_Result_u8[275] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_11: 
                        Faa_F_Rl_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Rr_AtActr_Cmd_Nwt_Faa_F_Rr_AtActr_Cmd_Nwt();
                        if (Faa_F_Rl_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[276] = Suite_1;
                            RAFT_Resp_Result_u8[277] = TestCase_11;
                            RAFT_Resp_Result_u8[278] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[276] = Suite_1;
                            RAFT_Resp_Result_u8[277] = TestCase_11;
                            RAFT_Resp_Result_u8[278] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_12: 
                        Faa_F_Fr_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_Frq_Fn_ZlFil_Ce_Hz_Faa_Frq_Fn_ZlFil_Ce_Hz();
                        if (Faa_F_Fr_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[279] = Suite_1;
                            RAFT_Resp_Result_u8[280] = TestCase_12;
                            RAFT_Resp_Result_u8[281] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[279] = Suite_1;
                            RAFT_Resp_Result_u8[280] = TestCase_12;
                            RAFT_Resp_Result_u8[281] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_13: 
                        Faa_F_Fl_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_Frq_Re_ZlFil_Ce_Hz_Faa_Frq_Re_ZlFil_Ce_Hz();
                        if (Faa_F_Fl_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[282] = Suite_1;
                            RAFT_Resp_Result_u8[283] = TestCase_13;
                            RAFT_Resp_Result_u8[284] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[282] = Suite_1;
                            RAFT_Resp_Result_u8[283] = TestCase_13;
                            RAFT_Resp_Result_u8[284] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_14: 
                        Asmc_1000Hz_F_Cmd_Crc_sig = Rte_IRead_RAFT_SWC_Main_Faa_Gain_Fn_ZlFil_Na_Faa_Gain_Fn_ZlFil_Na();
                        if (Asmc_1000Hz_F_Cmd_Crc_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[285] = Suite_1;
                            RAFT_Resp_Result_u8[286] = TestCase_14;
                            RAFT_Resp_Result_u8[287] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[285] = Suite_1;
                            RAFT_Resp_Result_u8[286] = TestCase_14;
                            RAFT_Resp_Result_u8[287] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_15: 
                        Asmc_1000Hz_F_Cmd_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Faa_Gain_Re_ZlFil_Na_Faa_Gain_Re_ZlFil_Na();
                        if (Asmc_1000Hz_F_Cmd_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[288] = Suite_1;
                            RAFT_Resp_Result_u8[289] = TestCase_15;
                            RAFT_Resp_Result_u8[290] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[288] = Suite_1;
                            RAFT_Resp_Result_u8[289] = TestCase_15;
                            RAFT_Resp_Result_u8[290] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_16: 
                        Faa_Sts_ZlMofr_Re_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Mofr_Fn_ZlGain_Na_Faa_Mofr_Fn_ZlGain_Na();
                        if (Faa_Sts_ZlMofr_Re_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[291] = Suite_1;
                            RAFT_Resp_Result_u8[292] = TestCase_16;
                            RAFT_Resp_Result_u8[293] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[291] = Suite_1;
                            RAFT_Resp_Result_u8[292] = TestCase_16;
                            RAFT_Resp_Result_u8[293] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_17: 
                        Faa_Gain_Re_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Mofr_Re_ZlGain_Na_Faa_Mofr_Re_ZlGain_Na();
                        if (Faa_Gain_Re_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[294] = Suite_1;
                            RAFT_Resp_Result_u8[295] = TestCase_17;
                            RAFT_Resp_Result_u8[296] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[294] = Suite_1;
                            RAFT_Resp_Result_u8[295] = TestCase_17;
                            RAFT_Resp_Result_u8[296] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_18: 
                        Faa_Wi_Re_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Sts_F_Qfr_Na_Faa_Sts_F_Qfr_Na();
                        if (Faa_Wi_Re_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[297] = Suite_1;
                            RAFT_Resp_Result_u8[298] = TestCase_18;
                            RAFT_Resp_Result_u8[299] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[297] = Suite_1;
                            RAFT_Resp_Result_u8[298] = TestCase_18;
                            RAFT_Resp_Result_u8[299] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_19: 
                        Faa_Frq_Re_ZlFil_Ce_Hz_sig = Rte_IRead_RAFT_SWC_Main_Faa_Sts_ZlMofr_Fn_Qfr_Na_Faa_Sts_ZlMofr_Fn_Qfr_Na();
                        if (Faa_Frq_Re_ZlFil_Ce_Hz_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[300] = Suite_1;
                            RAFT_Resp_Result_u8[301] = TestCase_19;
                            RAFT_Resp_Result_u8[302] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[300] = Suite_1;
                            RAFT_Resp_Result_u8[301] = TestCase_19;
                            RAFT_Resp_Result_u8[302] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_20: 
                        Faa_Mofr_Re_ZlGain_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Sts_ZlMofr_Re_Qfr_Na_Faa_Sts_ZlMofr_Re_Qfr_Na();
                        if (Faa_Mofr_Re_ZlGain_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[303] = Suite_1;
                            RAFT_Resp_Result_u8[304] = TestCase_20;
                            RAFT_Resp_Result_u8[305] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[303] = Suite_1;
                            RAFT_Resp_Result_u8[304] = TestCase_20;
                            RAFT_Resp_Result_u8[305] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_21: 
                        Faa_Sts_ZlMofr_Fn_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Wi_Fn_ZlFil_Na_Faa_Wi_Fn_ZlFil_Na();
                        if (Faa_Sts_ZlMofr_Fn_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[306] = Suite_1;
                            RAFT_Resp_Result_u8[307] = TestCase_21;
                            RAFT_Resp_Result_u8[308] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[306] = Suite_1;
                            RAFT_Resp_Result_u8[307] = TestCase_21;
                            RAFT_Resp_Result_u8[308] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_22: 
                        Faa_Gain_Fn_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Wi_Re_ZlFil_Na_Faa_Wi_Re_ZlFil_Na();
                        if (Faa_Gain_Fn_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[309] = Suite_1;
                            RAFT_Resp_Result_u8[310] = TestCase_22;
                            RAFT_Resp_Result_u8[311] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[309] = Suite_1;
                            RAFT_Resp_Result_u8[310] = TestCase_22;
                            RAFT_Resp_Result_u8[311] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_23: 
                        Faa_Wi_Fn_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehSpdLo_Na_Fas_Sts_VehSpdLo_Na();
                        if (Faa_Wi_Fn_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[312] = Suite_1;
                            RAFT_Resp_Result_u8[313] = TestCase_23;
                            RAFT_Resp_Result_u8[314] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[312] = Suite_1;
                            RAFT_Resp_Result_u8[313] = TestCase_23;
                            RAFT_Resp_Result_u8[314] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_24: 
                        Faa_Frq_Fn_ZlFil_Ce_Hz_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStaty_Na_Fas_Sts_VehStaty_Na();
                        if (Faa_Frq_Fn_ZlFil_Ce_Hz_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[315] = Suite_1;
                            RAFT_Resp_Result_u8[316] = TestCase_24;
                            RAFT_Resp_Result_u8[317] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[315] = Suite_1;
                            RAFT_Resp_Result_u8[316] = TestCase_24;
                            RAFT_Resp_Result_u8[317] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_25: 
                        Faa_Mofr_Fn_ZlGain_Na_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStsSpdLo_Qfr_Na_Fas_Sts_VehStsSpdLo_Qfr_Na();
                        if (Faa_Mofr_Fn_ZlGain_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[318] = Suite_1;
                            RAFT_Resp_Result_u8[319] = TestCase_25;
                            RAFT_Resp_Result_u8[320] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[318] = Suite_1;
                            RAFT_Resp_Result_u8[319] = TestCase_25;
                            RAFT_Resp_Result_u8[320] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_26: 
                        Asmc_100Hz_Zl_Mofr_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStsStaty_Qfr_Na_Fas_Sts_VehStsStaty_Qfr_Na();
                        if (Asmc_100Hz_Zl_Mofr_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[321] = Suite_1;
                            RAFT_Resp_Result_u8[322] = TestCase_26;
                            RAFT_Resp_Result_u8[323] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[321] = Suite_1;
                            RAFT_Resp_Result_u8[322] = TestCase_26;
                            RAFT_Resp_Result_u8[323] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                }
            break; 
    
            case Suite_2: 
                switch (Data[1])
                { 
    
                    case TestCase_0: 
                        Asmc_Req_DaHlthTest_Na_sig = Rte_IRead_RAFT_SWC_Main_Ascc_St_Req_Na_Ascc_St_Req_Na();
                        if (Asmc_Req_DaHlthTest_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[324] = Suite_2;
                            RAFT_Resp_Result_u8[325] = TestCase_0;
                            RAFT_Resp_Result_u8[326] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[324] = Suite_2;
                            RAFT_Resp_Result_u8[325] = TestCase_0;
                            RAFT_Resp_Result_u8[326] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_1: 
                        Ascc_St_Req_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_1000Hz_F_Cmd_AlvCtr_Asmc_1000Hz_F_Cmd_AlvCtr();
                        if (Ascc_St_Req_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[327] = Suite_2;
                            RAFT_Resp_Result_u8[328] = TestCase_1;
                            RAFT_Resp_Result_u8[329] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[327] = Suite_2;
                            RAFT_Resp_Result_u8[328] = TestCase_1;
                            RAFT_Resp_Result_u8[329] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_2: 
                        Asmc_25Hz_Sts_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Asmc_1000Hz_F_Cmd_Crc_Asmc_1000Hz_F_Cmd_Crc();
                        if (Asmc_25Hz_Sts_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[330] = Suite_2;
                            RAFT_Resp_Result_u8[331] = TestCase_2;
                            RAFT_Resp_Result_u8[332] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[330] = Suite_2;
                            RAFT_Resp_Result_u8[331] = TestCase_2;
                            RAFT_Resp_Result_u8[332] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_3: 
                        Fas_Sts_VehStsSpdLo_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Sts_VehStaty_AlvCtr_Asmc_100Hz_Sts_VehStaty_AlvCtr();
                        if (Fas_Sts_VehStsSpdLo_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[333] = Suite_2;
                            RAFT_Resp_Result_u8[334] = TestCase_3;
                            RAFT_Resp_Result_u8[335] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[333] = Suite_2;
                            RAFT_Resp_Result_u8[334] = TestCase_3;
                            RAFT_Resp_Result_u8[335] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_4: 
                        Fas_Sts_VehSpdLo_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Sts_VehStaty_Crc_Asmc_100Hz_Sts_VehStaty_Crc();
                        if (Fas_Sts_VehSpdLo_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[336] = Suite_2;
                            RAFT_Resp_Result_u8[337] = TestCase_4;
                            RAFT_Resp_Result_u8[338] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[336] = Suite_2;
                            RAFT_Resp_Result_u8[337] = TestCase_4;
                            RAFT_Resp_Result_u8[338] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_5: 
                        Fas_Sts_VehStsStaty_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_100Hz_Zl_Mofr_AlvCtr_Asmc_100Hz_Zl_Mofr_AlvCtr();
                        if (Fas_Sts_VehStsStaty_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[339] = Suite_2;
                            RAFT_Resp_Result_u8[340] = TestCase_5;
                            RAFT_Resp_Result_u8[341] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[339] = Suite_2;
                            RAFT_Resp_Result_u8[340] = TestCase_5;
                            RAFT_Resp_Result_u8[341] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_6: 
                        Fas_Sts_VehStaty_Na_sig = Rte_IRead_RAFT_SWC_Main_Asmc_25Hz_Sts_AlvCtr_Asmc_25Hz_Sts_AlvCtr();
                        if (Fas_Sts_VehStaty_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[342] = Suite_2;
                            RAFT_Resp_Result_u8[343] = TestCase_6;
                            RAFT_Resp_Result_u8[344] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[342] = Suite_2;
                            RAFT_Resp_Result_u8[343] = TestCase_6;
                            RAFT_Resp_Result_u8[344] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_7: 
                        Asmc_100Hz_Sts_VehStaty_Crc_sig = Rte_IRead_RAFT_SWC_Main_Asmc_Req_DaHlthTest_Na_Asmc_Req_DaHlthTest_Na();
                        if (Asmc_100Hz_Sts_VehStaty_Crc_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[345] = Suite_2;
                            RAFT_Resp_Result_u8[346] = TestCase_7;
                            RAFT_Resp_Result_u8[347] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[345] = Suite_2;
                            RAFT_Resp_Result_u8[346] = TestCase_7;
                            RAFT_Resp_Result_u8[347] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_8: 
                        Asmc_100Hz_Sts_VehStaty_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Fl_AtActr_Cmd_Nwt_Faa_F_Fl_AtActr_Cmd_Nwt();
                        if (Asmc_100Hz_Sts_VehStaty_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[348] = Suite_2;
                            RAFT_Resp_Result_u8[349] = TestCase_8;
                            RAFT_Resp_Result_u8[350] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[348] = Suite_2;
                            RAFT_Resp_Result_u8[349] = TestCase_8;
                            RAFT_Resp_Result_u8[350] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_9: 
                        Faa_Sts_F_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Fr_AtActr_Cmd_Nwt_Faa_F_Fr_AtActr_Cmd_Nwt();
                        if (Faa_Sts_F_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[351] = Suite_2;
                            RAFT_Resp_Result_u8[352] = TestCase_9;
                            RAFT_Resp_Result_u8[353] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[351] = Suite_2;
                            RAFT_Resp_Result_u8[352] = TestCase_9;
                            RAFT_Resp_Result_u8[353] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_10: 
                        Faa_F_Rr_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Rl_AtActr_Cmd_Nwt_Faa_F_Rl_AtActr_Cmd_Nwt();
                        if (Faa_F_Rr_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[354] = Suite_2;
                            RAFT_Resp_Result_u8[355] = TestCase_10;
                            RAFT_Resp_Result_u8[356] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[354] = Suite_2;
                            RAFT_Resp_Result_u8[355] = TestCase_10;
                            RAFT_Resp_Result_u8[356] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_11: 
                        Faa_F_Rl_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_F_Rr_AtActr_Cmd_Nwt_Faa_F_Rr_AtActr_Cmd_Nwt();
                        if (Faa_F_Rl_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[357] = Suite_2;
                            RAFT_Resp_Result_u8[358] = TestCase_11;
                            RAFT_Resp_Result_u8[359] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[357] = Suite_2;
                            RAFT_Resp_Result_u8[358] = TestCase_11;
                            RAFT_Resp_Result_u8[359] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_12: 
                        Faa_F_Fr_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_Frq_Fn_ZlFil_Ce_Hz_Faa_Frq_Fn_ZlFil_Ce_Hz();
                        if (Faa_F_Fr_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[360] = Suite_2;
                            RAFT_Resp_Result_u8[361] = TestCase_12;
                            RAFT_Resp_Result_u8[362] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[360] = Suite_2;
                            RAFT_Resp_Result_u8[361] = TestCase_12;
                            RAFT_Resp_Result_u8[362] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_13: 
                        Faa_F_Fl_AtActr_Cmd_Nwt_sig = Rte_IRead_RAFT_SWC_Main_Faa_Frq_Re_ZlFil_Ce_Hz_Faa_Frq_Re_ZlFil_Ce_Hz();
                        if (Faa_F_Fl_AtActr_Cmd_Nwt_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[363] = Suite_2;
                            RAFT_Resp_Result_u8[364] = TestCase_13;
                            RAFT_Resp_Result_u8[365] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[363] = Suite_2;
                            RAFT_Resp_Result_u8[364] = TestCase_13;
                            RAFT_Resp_Result_u8[365] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_14: 
                        Asmc_1000Hz_F_Cmd_Crc_sig = Rte_IRead_RAFT_SWC_Main_Faa_Gain_Fn_ZlFil_Na_Faa_Gain_Fn_ZlFil_Na();
                        if (Asmc_1000Hz_F_Cmd_Crc_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[366] = Suite_2;
                            RAFT_Resp_Result_u8[367] = TestCase_14;
                            RAFT_Resp_Result_u8[368] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[366] = Suite_2;
                            RAFT_Resp_Result_u8[367] = TestCase_14;
                            RAFT_Resp_Result_u8[368] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_15: 
                        Asmc_1000Hz_F_Cmd_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Faa_Gain_Re_ZlFil_Na_Faa_Gain_Re_ZlFil_Na();
                        if (Asmc_1000Hz_F_Cmd_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[369] = Suite_2;
                            RAFT_Resp_Result_u8[370] = TestCase_15;
                            RAFT_Resp_Result_u8[371] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[369] = Suite_2;
                            RAFT_Resp_Result_u8[370] = TestCase_15;
                            RAFT_Resp_Result_u8[371] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_16: 
                        Faa_Sts_ZlMofr_Re_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Mofr_Fn_ZlGain_Na_Faa_Mofr_Fn_ZlGain_Na();
                        if (Faa_Sts_ZlMofr_Re_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[372] = Suite_2;
                            RAFT_Resp_Result_u8[373] = TestCase_16;
                            RAFT_Resp_Result_u8[374] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[372] = Suite_2;
                            RAFT_Resp_Result_u8[373] = TestCase_16;
                            RAFT_Resp_Result_u8[374] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_17: 
                        Faa_Gain_Re_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Mofr_Re_ZlGain_Na_Faa_Mofr_Re_ZlGain_Na();
                        if (Faa_Gain_Re_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[375] = Suite_2;
                            RAFT_Resp_Result_u8[376] = TestCase_17;
                            RAFT_Resp_Result_u8[377] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[375] = Suite_2;
                            RAFT_Resp_Result_u8[376] = TestCase_17;
                            RAFT_Resp_Result_u8[377] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_18: 
                        Faa_Wi_Re_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Sts_F_Qfr_Na_Faa_Sts_F_Qfr_Na();
                        if (Faa_Wi_Re_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[378] = Suite_2;
                            RAFT_Resp_Result_u8[379] = TestCase_18;
                            RAFT_Resp_Result_u8[380] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[378] = Suite_2;
                            RAFT_Resp_Result_u8[379] = TestCase_18;
                            RAFT_Resp_Result_u8[380] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_19: 
                        Faa_Frq_Re_ZlFil_Ce_Hz_sig = Rte_IRead_RAFT_SWC_Main_Faa_Sts_ZlMofr_Fn_Qfr_Na_Faa_Sts_ZlMofr_Fn_Qfr_Na();
                        if (Faa_Frq_Re_ZlFil_Ce_Hz_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[381] = Suite_2;
                            RAFT_Resp_Result_u8[382] = TestCase_19;
                            RAFT_Resp_Result_u8[383] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[381] = Suite_2;
                            RAFT_Resp_Result_u8[382] = TestCase_19;
                            RAFT_Resp_Result_u8[383] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_20: 
                        Faa_Mofr_Re_ZlGain_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Sts_ZlMofr_Re_Qfr_Na_Faa_Sts_ZlMofr_Re_Qfr_Na();
                        if (Faa_Mofr_Re_ZlGain_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[384] = Suite_2;
                            RAFT_Resp_Result_u8[385] = TestCase_20;
                            RAFT_Resp_Result_u8[386] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[384] = Suite_2;
                            RAFT_Resp_Result_u8[385] = TestCase_20;
                            RAFT_Resp_Result_u8[386] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_21: 
                        Faa_Sts_ZlMofr_Fn_Qfr_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Wi_Fn_ZlFil_Na_Faa_Wi_Fn_ZlFil_Na();
                        if (Faa_Sts_ZlMofr_Fn_Qfr_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[387] = Suite_2;
                            RAFT_Resp_Result_u8[388] = TestCase_21;
                            RAFT_Resp_Result_u8[389] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[387] = Suite_2;
                            RAFT_Resp_Result_u8[388] = TestCase_21;
                            RAFT_Resp_Result_u8[389] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_22: 
                        Faa_Gain_Fn_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Faa_Wi_Re_ZlFil_Na_Faa_Wi_Re_ZlFil_Na();
                        if (Faa_Gain_Fn_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[390] = Suite_2;
                            RAFT_Resp_Result_u8[391] = TestCase_22;
                            RAFT_Resp_Result_u8[392] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[390] = Suite_2;
                            RAFT_Resp_Result_u8[391] = TestCase_22;
                            RAFT_Resp_Result_u8[392] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_23: 
                        Faa_Wi_Fn_ZlFil_Na_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehSpdLo_Na_Fas_Sts_VehSpdLo_Na();
                        if (Faa_Wi_Fn_ZlFil_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[393] = Suite_2;
                            RAFT_Resp_Result_u8[394] = TestCase_23;
                            RAFT_Resp_Result_u8[395] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[393] = Suite_2;
                            RAFT_Resp_Result_u8[394] = TestCase_23;
                            RAFT_Resp_Result_u8[395] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_24: 
                        Faa_Frq_Fn_ZlFil_Ce_Hz_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStaty_Na_Fas_Sts_VehStaty_Na();
                        if (Faa_Frq_Fn_ZlFil_Ce_Hz_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[396] = Suite_2;
                            RAFT_Resp_Result_u8[397] = TestCase_24;
                            RAFT_Resp_Result_u8[398] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[396] = Suite_2;
                            RAFT_Resp_Result_u8[397] = TestCase_24;
                            RAFT_Resp_Result_u8[398] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_25: 
                        Faa_Mofr_Fn_ZlGain_Na_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStsSpdLo_Qfr_Na_Fas_Sts_VehStsSpdLo_Qfr_Na();
                        if (Faa_Mofr_Fn_ZlGain_Na_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[399] = Suite_2;
                            RAFT_Resp_Result_u8[400] = TestCase_25;
                            RAFT_Resp_Result_u8[401] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[399] = Suite_2;
                            RAFT_Resp_Result_u8[400] = TestCase_25;
                            RAFT_Resp_Result_u8[401] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                    case TestCase_26: 
                        Asmc_100Hz_Zl_Mofr_AlvCtr_sig = Rte_IRead_RAFT_SWC_Main_Fas_Sts_VehStsStaty_Qfr_Na_Fas_Sts_VehStsStaty_Qfr_Na();
                        if (Asmc_100Hz_Zl_Mofr_AlvCtr_sig == Data[2])
                        {
                            /*Response format:
                            * Byte 0: Test suite number
                            * Byte 1: Test case number
                            * Byte 2: Test Result*/
                            RAFT_Resp_Result_u8[402] = Suite_2;
                            RAFT_Resp_Result_u8[403] = TestCase_26;
                            RAFT_Resp_Result_u8[404] = RTE_E_OK;
                            retval_u8 = RTE_E_OK;
                        }
                        else
                        {
                            RAFT_Resp_Result_u8[402] = Suite_2;
                            RAFT_Resp_Result_u8[403] = TestCase_26;
                            RAFT_Resp_Result_u8[404] = E_NOT_OK;  
                            retval_u8 = E_NOT_OK;
                        }
                        break; 
                                
    
                }
            break; 
               
        }
    