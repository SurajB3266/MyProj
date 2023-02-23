###########################################################################################################
#                                                                                                         #
#                         Pyhton code to find and create a text file containing the RTE call              #
#                                                                                                         #
#                                      RealThingks India                                                  #
#                                                                                                         #
###########################################################################################################
#---------------------------------------------------------------------------------------------------------#
#                                            DISCRIPTION                                                  #
#---------------------------------------------------------------------------------------------------------#
#Find the *   Implicit S/R API: in the RAFT_SEC.c file 
#create a text (RTE_file.txt)file containing all the data inside the Implicit S/R API:
#---------------------------------------------------------------------------------------------------------#
#                                             Import libraries                                            #
#---------------------------------------------------------------------------------------------------------#
import os
#-------------------------------------------------------------------------------------------------------- #
#                                                Decleration                                              #
#---------------------------------------------------------------------------------------------------------#
global cwd
cwd = os.getcwd()
cwd = str(cwd).replace('/','\\')




def CreateRTEFile(path):
    # path of Generated RAFT_swc.c 
    RaftComponent_C_CodeFilePath = path
    mylines = []  #Empty list to store rte api and data type
    flag = False
    #find in the RAFT_SWC.c
    find="*   Implicit S/R API:"
    find_till=" Mode Interfaces"
    # destination_file=f"{cwd}\\input\\Rte\\"
    destination_file = os.path.join(cwd, "internal", "Rte")
    os.makedirs(destination_file, exist_ok=True)
    

    #---------------------------------------------------------------------------------------------------------#
    #                                       Creating the list by parsing the SWC.c                            #
    #---------------------------------------------------------------------------------------------------------#
    with open(RaftComponent_C_CodeFilePath, 'rt', encoding='utf-8') as myfile:
        for line in myfile:
            if line.strip().startswith(find): #split the file when the *   Implicit S/R API:" is found in the RAFT_SWC.c
                flag = not flag
            if flag:
                mylines.append(line) #Find till " Mode Interfaces"
                if find_till in line.strip():
                    break

    with open(f"{destination_file}\\RTE_file.txt","w") as f:
        f.write("".join(mylines))

    # f = open(destination_file, "w+") 
    # f.write("".join(mylines)) #Store the list in the RTE_file.txt
    f.close() 
