# Documentation of Changes in the Labview Code
## Title of the document
Design and Implementation of User Interface for Labview Application

## Introduction

This document outlines the significant changes made to the naming conventions within our project. The primary objective of these changes is to enhance readability, maintainability, and consistency across our codebase. 
The changes span across various components of our project, including VI, Functions, TCP Client, and Variables. Each section in this document corresponds to these components and provides a detailed overview of the old names, the new names, and a brief description of their functionalities.
By standardizing our naming conventions, we aim to create a more intuitive and user-friendly environment for both our team and any future contributors. This will not only simplify the process of understanding the code but also make it easier to debug, test, and enhance the project in the future.
Please refer to the table of contents for easy navigation through the document.

## GUI App
**Build description:** The GUI application is the main interface for the user to interact with the system. It is responsible for displaying the data, sending commands to the microcontroller, and handling errors. The GUI application is built using LabVIEW, a graphical programming language that allows for easy and intuitive development of user interfaces.

## VI Changes
### Main_menu4 -> Main_menu
**Old Name**: `Main_menu4`
**New Name**: `Main_menu`  
**Description:** The main menu function acts as the focal point for navigating and utilizing the diverse range of features and capabilities within our application. When users initiate the application, they encounter a user-friendly menu interface, offering a variety of options that cater to their specific requirements.
Key functionalities include:
- Initiating window plots for data visualization
- Establishing communication with microcontrollers
- Implementing robust error handling mechanisms

### New_plot1 -> Window_plot
**Old Name**: `New_plot1`
**New Name**: `Window_plot`  
**Description:** This window has the capability to visualize and analyze the graphs of the stored signals from the Main_menu.

### from_HW -> Call_signal_fromHW
**Old Name**: `from_HW`
**New Name**: `Call_signal_fromHW`  
**Description**: Through this function you can select the stored signals from the Main_menu.

### from_file -> Call_signal_fromfile
**Old Name**: `from_file`
**New Name**: `Call_signal_fromfile`  
**Desciption**: Through this function you can select the signals stored in a CSV file.

## Functions Changes

### Function_new plot -> Fc_new_plot
**Old Name**: `Function_new plot`
**New Name**: `Fc_new_plot`
**Desciption**: This function initiates the creation of a new window for graphing the stored controller signals.

### Getting_TRACE DATA -> Fc_Get_TRACEDATA
**Old Name**: `Getting_TRACE DATA`
**New Name**: `Fc_Get_TRACEDATA`  
**Desciption**: This function calls the microcontroller to obtain the signal data and stores them at the time of the request, into the "Signals_value_Array" variable.
	
### String2ArrayDouble -> String2ArrayDbl
**Old Name**: `String2ArrayDouble`
**New Name**: `String2ArrayDbl`  
**Desciption**: This function converts a string into an array of doubles.

### Function_update_parameters_frommicro -> Fc_update_params_from_uc
**Old Name**: `Function_update_parameters_frommicro`
**New Name**: `Fc_update_params_from_uc`  
**Desciption**: This function updates the parameters from the microcontroller.

### Send_Msj_Nplot -> Fc_Send_Msj_Nplot
**Old Name**: `Send_Msj_Nplot`
**New Name**: `Fc_Send_Msj_Nplot`
**Desciption**: Temporal function to send message to each window plot.

### Function_for_start record -> Fc_start_record
**Old Name**: `Function_for_start record`
**New Name**: `Fc_start_record`
**Desciption**: This function starts the record of the signals in the application.

### receiver_queue_Main_menu -> Fc_receiver_queue_Main_menu
**Old Name**: `receiver_queue_Main_menu`
**New Name**: `Fc_receiver_queue_Main_menu`
**Desciption**: This function receives the data from the active windows and stores it in the queue to send in the main menu.

### Function_to CS Enable -> Fc_CS_Enable
**Old Name**: `Function_to CS Enable`
**New Name**: `Fc_to_CS_Enable`
**Desciption**: This function enables the control system.

### Function_SaveCTRLparams -> Fc_SaveCTRLparams
**Old Name**: `Function_SaveCTRLparams`
**New Name**: `Fc_SaveCTRLparams`
**Desciption**: This function saves the control parameters from CS_IF_Params.

### Function_to_define_CSstatus -> Fc_to_define_CSstatus
**Old Name**: `Function_to_define_CSstatus`
**New Name**: `Fc_to_define_CSstatus`
**Desciption**: This function defines the current status of the control system.

### Function_save_conf_tomicro -> Fc_save_conf_to_uc
**Old Name**: `Function_save_conf_tomicro`
**New Name**: `Fc_save_conf_to_uc`
**Desciption**: This function saves the configuration to communicate with the microcontroller.

### Function_evaluate_state -> Fc_evaluate_state
**Old Name**: `Function_evaluate_state`
**New Name**: `Fc_evaluate_state`
**Desciption**: This function evaluates the execution state of the active window plot.

### Function_for_MenuSelections -> Fc_MenuSelections
**Old Name**: `Function_for_MenuSelections`
**New Name**: `Fc_MenuSelections`
**Desciption**: This function is used to select possible selection in the current window plot.

### Function_queue receiver -> Fc_queue_receiver2Window
**Old Name**: `Function_queue receiver`
**New Name**: `Fc_queue_receiver2Window`
**Desciption**: This function receives the data from the main menu and stores it in the queue to send in the active window plot.

### Function_2update_waveform graph -> Fc_2update_graph
**Old Name**: `Function_2update_waveform graph`
**New Name**: `Fc_2update_graph`
**Desciption**: This function updates the waveform graph.

### String2Array
**Description**: This function converts a string into an array string

### ArrayS2ArrayAx
**Description**: This function converts an array of strings into an array of arrays of numeric values.

#### Array2Matrix_test -> Array2Matrix
**Old Name**: `Array2Matrix_test`
**New Name**: `Array2Matrix`
**Desciption**: This function converts an array of numeric values into a matrix.


## TCP Client Changes

### TCP Client_33 -> Fc_TCP_Client_33
**Old Name**: `TCP Client_33`
**New Name**: `Fc_TCP_Client_33`  
**Desciption**: This function follows the tcp ip protocol to communicate with the microcontroller depending on the command (CMD) to be used. Version #33
#### List of commands
- 0-> OCP_IF_CMD_TRACE_READ = 0, //LV: SIZE - CMD - ID || RESPONSE: SIZE - DATA
- 1-> OCP_IF_CMD_TRACE_RESET, //SIZE - CMD - ID || RESPONSE: SIZE
- 2-> OCP_IF_CMD_TRACE_GET_SIZE, //SIZE - CMD - ID || RESPONSE: SIZE - TRACE_SIZE (4 bztes)
- 3-> OCP_IF_CMD_TRACE_SET_SIZE, //SIZE - CMD - ID - TRACE_SIZE ( 4 bytes) || RESPONSE: SIZE
- 4-> OCP_IF_CMD_TRACE_GET_NUMBER_SIGNALS, //SIZE - CMD - ID || RESPONSE: SIZE - NB_SIGNALS (4 bytes)
- 5-> OCP_IF_CMD_TRACE_GET_SIGNALS_NAMES, //SIZE - CMD - ID || RESPONSE: SIZE - string
- 6-> OCP_IF_CMD_TRACE_GET_NUMBER_TRACES, //SIZE - CMD  || RESPONSE: SIZE - NB_TRACES (4 bytes)
- 7-> OCP_IF_CMD_TRACE_GET_TRACES_NAMES, //SIZE - CMD || RESPONSE: SIZE - NB_TRACES (N bytes)
- 8-> OCP_IF_CMD_TRACE_GET_ADDRESS, //SIZE - CMD - ID || RESPONSE: SIZE - TRACE ADDRESS (4 bytes)
- 9-> OCP_IF_CMD_CS_STATUS, //SIZE - CMD - ID || RESPONSE: SIZE - CS STATUS (4 bytes)
- 10-> OCP_IF_CMD_CS_ENABLE, //SIZE - CMD - ID || RESPONSE: SIZE
- 11-> OCP_IF_CMD_CS_DISABLE, //SIZE - CMD - ID || RESPONSE: SIZE
- 12-> OCP_IF_CMD_CS_CONTROLLER_IF, //SIZE - CMD - ID - DATA (N) || RESPONSE: SIZE - DATA (M)
- 13-> OCP_IF_CMD_CS_HARDWARE_IF, //SIZE - CMD - ID - DATA (N) || RESPONSE: SIZE - DATA (M)
- 14-> OCP_IF_CMD_CS_GET_NUMBER_CONTROLLERS, //SIZE - CMD || RESPONSE: SIZE - NB CSs
- 15-> OCP_IF_CMD_CS_GET_CONTROLLERS_NAMES, //SIZE - CMD || RESPONSE: SIZE - string NAMES CSs

### TCP Client_34 -> Fc_TCP_Client_34
**Old Name**: `TCP Client_34`
**New Name**: `Fc_TCP_Client_34`  
**Description**: This function follows the tcp ip protocol to communicate with the microcontroller depending on the command (CMD) to be used. Version #34. Change data parameters
#### List of commands
- 0-> OCP_IF_CMD_TRACE_READ = 0, //LV: SIZE - CMD - ID || RESPONSE: SIZE - DATA
- 1-> OCP_IF_CMD_TRACE_RESET, //SIZE - CMD - ID || RESPONSE: SIZE
- 2-> OCP_IF_CMD_TRACE_GET_SIZE, //SIZE - CMD - ID || RESPONSE: SIZE - TRACE_SIZE (4 bztes)
- 3-> OCP_IF_CMD_TRACE_SET_SIZE, //SIZE - CMD - ID - TRACE_SIZE ( 4 bytes) || RESPONSE: SIZE
- 4-> OCP_IF_CMD_TRACE_GET_NUMBER_SIGNALS, //SIZE - CMD - ID || RESPONSE: SIZE - NB_SIGNALS (4 bytes)
- 5-> OCP_IF_CMD_TRACE_GET_SIGNALS_NAMES, //SIZE - CMD - ID || RESPONSE: SIZE - string
- 6-> OCP_IF_CMD_TRACE_GET_NUMBER_TRACES, //SIZE - CMD  || RESPONSE: SIZE - NB_TRACES (4 bytes)
- 7-> OCP_IF_CMD_TRACE_GET_TRACES_NAMES, //SIZE - CMD || RESPONSE: SIZE - NB_TRACES (N bytes)
- 8-> OCP_IF_CMD_TRACE_GET_ADDRESS, //SIZE - CMD - ID || RESPONSE: SIZE - TRACE ADDRESS (4 bytes)
- 9-> OCP_IF_CMD_CS_STATUS, //SIZE - CMD - ID || RESPONSE: SIZE - CS STATUS (4 bytes)
- 10-> OCP_IF_CMD_CS_ENABLE, //SIZE - CMD - ID || RESPONSE: SIZE
- 11-> OCP_IF_CMD_CS_DISABLE, //SIZE - CMD - ID || RESPONSE: SIZE
- 12-> OCP_IF_CMD_CS_CONTROLLER_IF, //SIZE - CMD - ID - DATA (N) || RESPONSE: SIZE - DATA (M)
- 13-> OCP_IF_CMD_CS_HARDWARE_IF, //SIZE - CMD - ID - DATA (N) || RESPONSE: SIZE - DATA (M)
- 14-> OCP_IF_CMD_CS_GET_NUMBER_CONTROLLERS, //SIZE - CMD || RESPONSE: SIZE - NB CSs
- 15-> OCP_IF_CMD_CS_GET_CONTROLLERS_NAMES, //SIZE - CMD || RESPONSE: SIZE - string NAMES CSs

### TCP Client_Get data signals -> Fc_TCP_Client_GetDatasignals
**Old Name**: `TCP Client_Get data signals`
**New Name**: `Fc_TCP_Client_GetDatasignals`  

## Variables Changes
### Variables1 -> Share_Variables
**Old Name**: `Variables1`
**New Name**: `Share_Variables`  
**Desciption**: In this section are all the variables declared and used to share data to the Window_plot from the Main_menu.

### List of variables	
1. Close_all_wplots
2. Global_refresh_time
3. Mode_signal_conf
4. number_signals
5. Signals_name
6. Signals_value_Array
7. Signals_value_string
8. Trace_name
