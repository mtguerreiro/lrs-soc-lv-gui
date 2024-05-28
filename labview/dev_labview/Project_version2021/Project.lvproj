<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="21008000">
	<Property Name="CCSymbols" Type="Str"></Property>
	<Property Name="NI.LV.All.SourceOnly" Type="Bool">false</Property>
	<Property Name="NI.Project.Description" Type="Str">The project is designed to facilitate interfacing with control systems and traces. It aims to achieve the following objectives:
Embedded controllers may contain numerous controllers and traces.
An interface will grant access to control systems and plotting traces.</Property>
	<Property Name="SMProvider.SMVersion" Type="Int">201310</Property>
	<Property Name="varPersistentID:{2FD70FF1-0CF7-4534-A776-1EC0D4C2A581}" Type="Ref">/My Computer/Share_Variables.lvlib/Signals_value_string</Property>
	<Property Name="varPersistentID:{363DF3D9-D8B8-4F19-8F38-3ECF772803CE}" Type="Ref">/My Computer/Share_Variables.lvlib/Signals_name</Property>
	<Property Name="varPersistentID:{43D425C3-DC9C-4DC9-9D7E-1B310843F631}" Type="Ref">/My Computer/Share_Variables.lvlib/Mode_signal_conf</Property>
	<Property Name="varPersistentID:{468564A8-839E-48BE-8105-628EAE285AC5}" Type="Ref">/My Computer/Share_Variables.lvlib/Signals_value_Array</Property>
	<Property Name="varPersistentID:{4FD7655C-6099-46C5-A8F8-9C7AA09BE3FD}" Type="Ref">/My Computer/Share_Variables.lvlib/Trace_name</Property>
	<Property Name="varPersistentID:{6605A8E9-DBE8-4E3D-97B9-2ADBF190306F}" Type="Ref">/My Computer/Share_Variables.lvlib/Samples_per_signal</Property>
	<Property Name="varPersistentID:{71F10532-AEA6-4ADE-90D3-CE81E849D6E3}" Type="Ref">/My Computer/Share_Variables.lvlib/Close_all_wplots</Property>
	<Property Name="varPersistentID:{7A163EED-FD73-4001-9628-C2BA347AAFC0}" Type="Ref">/My Computer/Share_Variables.lvlib/Global_refresh_time</Property>
	<Property Name="varPersistentID:{A28CA767-DF3E-4269-9A6E-C2042F133929}" Type="Ref">/My Computer/Share_Variables.lvlib/number_signals</Property>
	<Item Name="My Computer" Type="My Computer">
		<Property Name="IOScan.Faults" Type="Str"></Property>
		<Property Name="IOScan.NetVarPeriod" Type="UInt">100</Property>
		<Property Name="IOScan.NetWatchdogEnabled" Type="Bool">false</Property>
		<Property Name="IOScan.Period" Type="UInt">10000</Property>
		<Property Name="IOScan.PowerupMode" Type="UInt">0</Property>
		<Property Name="IOScan.Priority" Type="UInt">9</Property>
		<Property Name="IOScan.ReportModeConflict" Type="Bool">true</Property>
		<Property Name="IOScan.StartEngineOnDeploy" Type="Bool">false</Property>
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Functions" Type="Folder">
			<Item Name="Array2Matrix.vi" Type="VI" URL="../Array2Matrix.vi"/>
			<Item Name="ArrayS2ArrayAx_.vi" Type="VI" URL="../ArrayS2ArrayAx_.vi"/>
			<Item Name="Export image.vi" Type="VI" URL="../Export image.vi"/>
			<Item Name="Export plot data to Clipboard.vi" Type="VI" URL="../Export plot data to Clipboard.vi"/>
			<Item Name="Fc_2update_graph.vi" Type="VI" URL="../Fc_2update_graph.vi"/>
			<Item Name="Fc_evaluate_state.vi" Type="VI" URL="../Fc_evaluate_state.vi"/>
			<Item Name="Fc_Get_TRACEDATA.vi" Type="VI" URL="../Fc_Get_TRACEDATA.vi"/>
			<Item Name="Fc_MenuSelections.vi" Type="VI" URL="../Fc_MenuSelections.vi"/>
			<Item Name="Fc_new_plot.vi" Type="VI" URL="../Fc_new_plot.vi"/>
			<Item Name="Fc_queue_receiver2Window.vi" Type="VI" URL="../Fc_queue_receiver2Window.vi"/>
			<Item Name="Fc_receiver_queue_Main_menu.vi" Type="VI" URL="../Fc_receiver_queue_Main_menu.vi"/>
			<Item Name="Fc_save_conf_to_uc.vi" Type="VI" URL="../Fc_save_conf_to_uc.vi"/>
			<Item Name="Fc_SaveCTRLparams.vi" Type="VI" URL="../Fc_SaveCTRLparams.vi"/>
			<Item Name="Fc_Send_Msj_Nplot.vi" Type="VI" URL="../Fc_Send_Msj_Nplot.vi"/>
			<Item Name="Fc_start_record.vi" Type="VI" URL="../Fc_start_record.vi"/>
			<Item Name="Fc_to_CS_Enable.vi" Type="VI" URL="../Fc_to_CS_Enable.vi"/>
			<Item Name="Fc_to_define_CSstatus.vi" Type="VI" URL="../Fc_to_define_CSstatus.vi"/>
			<Item Name="Fc_update_params_from_uc.vi" Type="VI" URL="../Fc_update_params_from_uc.vi"/>
			<Item Name="receiver_Main_menu.vi" Type="VI" URL="../receiver_Main_menu.vi"/>
			<Item Name="String2Array.vi" Type="VI" URL="../String2Array.vi"/>
			<Item Name="String2ArrayDbl.vi" Type="VI" URL="../String2ArrayDbl.vi"/>
			<Item Name="String2ArrayInt.vi" Type="VI" URL="../String2ArrayInt.vi"/>
			<Item Name="String2Matrix.vi" Type="VI" URL="../String2Matrix.vi"/>
		</Item>
		<Item Name="Old functions" Type="Folder">
			<Item Name="From file_test1.vi" Type="VI" URL="../From file_test1.vi"/>
			<Item Name="From HW_Allrequest.vi" Type="VI" URL="../From HW_Allrequest.vi"/>
			<Item Name="Main menu_2_test2.vi" Type="VI" URL="../Main menu_2_test2.vi"/>
			<Item Name="Main menu_3.vi" Type="VI" URL="../Main menu_3.vi"/>
			<Item Name="Main menu_3_enablepp.vi" Type="VI" URL="../Main menu_3_enablepp.vi"/>
			<Item Name="New plot.vi" Type="VI" URL="../New plot.vi"/>
			<Item Name="New plot1_old.vi" Type="VI" URL="../New plot1_old.vi"/>
		</Item>
		<Item Name="TCP" Type="Folder">
			<Item Name="Fc_TCP_Client_33.vi" Type="VI" URL="../Fc_TCP_Client_33.vi"/>
			<Item Name="Fc_TCP_Client_34.vi" Type="VI" URL="../Fc_TCP_Client_34.vi"/>
			<Item Name="Fc_TCP_Client_GetDatasignals.vi" Type="VI" URL="../Fc_TCP_Client_GetDatasignals.vi"/>
			<Item Name="TCP Client.vi" Type="VI" URL="../TCP Client.vi"/>
			<Item Name="TCP Client_21.vi" Type="VI" URL="../TCP Client_21.vi"/>
			<Item Name="TCP Client_31.vi" Type="VI" URL="../TCP Client_31.vi"/>
			<Item Name="TCP Client_32.vi" Type="VI" URL="../TCP Client_32.vi"/>
			<Item Name="TCP Client_34_enablep.vi" Type="VI" URL="../TCP Client_34_enablep.vi"/>
		</Item>
		<Item Name="test functions" Type="Folder">
			<Item Name="Array2Matrix_test.vi" Type="VI" URL="../Array2Matrix_test.vi"/>
			<Item Name="Send Message_test.vi" Type="VI" URL="../Send Message_test.vi"/>
			<Item Name="Show_virtual variables.vi" Type="VI" URL="../Show_virtual variables.vi"/>
		</Item>
		<Item Name="Call_signal_fromfile.vi" Type="VI" URL="../Call_signal_fromfile.vi"/>
		<Item Name="Call_signal_fromHW.vi" Type="VI" URL="../Call_signal_fromHW.vi"/>
		<Item Name="Main_menu.vi" Type="VI" URL="../Main_menu.vi"/>
		<Item Name="Share_Variables.lvlib" Type="Library" URL="../Share_Variables.lvlib"/>
		<Item Name="Window_plot.vi" Type="VI" URL="../Window_plot.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="BuildHelpPath.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/BuildHelpPath.vi"/>
				<Item Name="Check for Equality.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/Check for Equality.vi"/>
				<Item Name="Check for multiple of dt.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/Check for multiple of dt.vi"/>
				<Item Name="Check Special Tags.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Check Special Tags.vi"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="Close File+.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Close File+.vi"/>
				<Item Name="compatReadText.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/compatReadText.vi"/>
				<Item Name="Convert property node font to graphics font.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Convert property node font to graphics font.vi"/>
				<Item Name="Details Display Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Details Display Dialog.vi"/>
				<Item Name="DialogType.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/DialogType.ctl"/>
				<Item Name="DialogTypeEnum.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/DialogTypeEnum.ctl"/>
				<Item Name="DTbl Digital Size.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DTblOps.llb/DTbl Digital Size.vi"/>
				<Item Name="DTbl Digital Subset.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DTblOps.llb/DTbl Digital Subset.vi"/>
				<Item Name="DWDT Digital Size.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DWDTOps.llb/DWDT Digital Size.vi"/>
				<Item Name="DWDT Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DWDTOps.llb/DWDT Error Code.vi"/>
				<Item Name="DWDT Get Waveform Subset.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/DWDTOps.llb/DWDT Get Waveform Subset.vi"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="Error Code Database.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Code Database.vi"/>
				<Item Name="ErrWarn.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/ErrWarn.ctl"/>
				<Item Name="eventvkey.ctl" Type="VI" URL="/&lt;vilib&gt;/event_ctls.llb/eventvkey.ctl"/>
				<Item Name="Find First Error.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Find First Error.vi"/>
				<Item Name="Find Tag.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Find Tag.vi"/>
				<Item Name="Format Message String.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Format Message String.vi"/>
				<Item Name="General Error Handler Core CORE.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/General Error Handler Core CORE.vi"/>
				<Item Name="General Error Handler.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/General Error Handler.vi"/>
				<Item Name="Get String Text Bounds.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Get String Text Bounds.vi"/>
				<Item Name="Get Text Rect.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Get Text Rect.vi"/>
				<Item Name="Get Waveform Subset.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/Get Waveform Subset.vi"/>
				<Item Name="GetHelpDir.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/GetHelpDir.vi"/>
				<Item Name="GetRTHostConnectedProp.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/GetRTHostConnectedProp.vi"/>
				<Item Name="Longest Line Length in Pixels.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Longest Line Length in Pixels.vi"/>
				<Item Name="LVBoundsTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVBoundsTypeDef.ctl"/>
				<Item Name="lveventtype.ctl" Type="VI" URL="/&lt;vilib&gt;/event_ctls.llb/lveventtype.ctl"/>
				<Item Name="LVRectTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVRectTypeDef.ctl"/>
				<Item Name="NI_AALBase.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALBase.lvlib"/>
				<Item Name="NI_AALPro.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALPro.lvlib"/>
				<Item Name="NI_Gmath.lvlib" Type="Library" URL="/&lt;vilib&gt;/gmath/NI_Gmath.lvlib"/>
				<Item Name="Not Found Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Not Found Dialog.vi"/>
				<Item Name="Number of Waveform Samples.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/Number of Waveform Samples.vi"/>
				<Item Name="Open File+.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Open File+.vi"/>
				<Item Name="Read Delimited Spreadsheet (DBL).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read Delimited Spreadsheet (DBL).vi"/>
				<Item Name="Read Delimited Spreadsheet (I64).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read Delimited Spreadsheet (I64).vi"/>
				<Item Name="Read Delimited Spreadsheet (string).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read Delimited Spreadsheet (string).vi"/>
				<Item Name="Read Delimited Spreadsheet.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read Delimited Spreadsheet.vi"/>
				<Item Name="Read File+ (string).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read File+ (string).vi"/>
				<Item Name="Read Lines From File (with error IO).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read Lines From File (with error IO).vi"/>
				<Item Name="Search and Replace Pattern.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Search and Replace Pattern.vi"/>
				<Item Name="Set Bold Text.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Set Bold Text.vi"/>
				<Item Name="Set String Value.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Set String Value.vi"/>
				<Item Name="Simple Error Handler.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Simple Error Handler.vi"/>
				<Item Name="Space Constant.vi" Type="VI" URL="/&lt;vilib&gt;/dlg_ctls.llb/Space Constant.vi"/>
				<Item Name="System Exec.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/system.llb/System Exec.vi"/>
				<Item Name="TagReturnType.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/TagReturnType.ctl"/>
				<Item Name="Three Button Dialog CORE.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Three Button Dialog CORE.vi"/>
				<Item Name="Three Button Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Three Button Dialog.vi"/>
				<Item Name="Trim Whitespace One-Sided.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace One-Sided.vi"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="WDT Get Waveform Subset CDB.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/WDT Get Waveform Subset CDB.vi"/>
				<Item Name="WDT Get Waveform Subset DBL.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/WDT Get Waveform Subset DBL.vi"/>
				<Item Name="WDT Get Waveform Subset EXT.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/WDT Get Waveform Subset EXT.vi"/>
				<Item Name="WDT Get Waveform Subset I8.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/WDT Get Waveform Subset I8.vi"/>
				<Item Name="WDT Get Waveform Subset I16.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/WDT Get Waveform Subset I16.vi"/>
				<Item Name="WDT Get Waveform Subset I32.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/WDT Get Waveform Subset I32.vi"/>
				<Item Name="WDT Get Waveform Subset SGL.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/WDT Get Waveform Subset SGL.vi"/>
				<Item Name="WDT Number of Waveform Samples CDB.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/WDT Number of Waveform Samples CDB.vi"/>
				<Item Name="WDT Number of Waveform Samples DBL.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/WDT Number of Waveform Samples DBL.vi"/>
				<Item Name="WDT Number of Waveform Samples EXT.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/WDT Number of Waveform Samples EXT.vi"/>
				<Item Name="WDT Number of Waveform Samples I8.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/WDT Number of Waveform Samples I8.vi"/>
				<Item Name="WDT Number of Waveform Samples I16.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/WDT Number of Waveform Samples I16.vi"/>
				<Item Name="WDT Number of Waveform Samples I32.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/WDT Number of Waveform Samples I32.vi"/>
				<Item Name="WDT Number of Waveform Samples SGL.vi" Type="VI" URL="/&lt;vilib&gt;/Waveform/WDTOps.llb/WDT Number of Waveform Samples SGL.vi"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
				<Item Name="Write Delimited Spreadsheet (DBL).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write Delimited Spreadsheet (DBL).vi"/>
				<Item Name="Write Delimited Spreadsheet (I64).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write Delimited Spreadsheet (I64).vi"/>
				<Item Name="Write Delimited Spreadsheet (string).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write Delimited Spreadsheet (string).vi"/>
				<Item Name="Write Delimited Spreadsheet.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write Delimited Spreadsheet.vi"/>
				<Item Name="Write Spreadsheet String.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Write Spreadsheet String.vi"/>
			</Item>
			<Item Name="lvanlys.dll" Type="Document" URL="/&lt;resource&gt;/lvanlys.dll"/>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="GUI App" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{8006EE31-BE82-4D59-A1E2-662AA193DB18}</Property>
				<Property Name="App_INI_GUID" Type="Str">{922FB147-37F4-40FB-BA8D-EDCE677BC50C}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="App_serverType" Type="Int">0</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{E76AF4CE-08EC-45EC-9F59-71A6CEF3DD73}</Property>
				<Property Name="Bld_buildSpecDescription" Type="Str">The GUI application is the main interface for the user to interact with the system. It is responsible for displaying the data, sending commands to the microcontroller, and handling errors. The GUI application is built using LabVIEW, a graphical programming language that allows for easy and intuitive development of user interfaces.</Property>
				<Property Name="Bld_buildSpecName" Type="Str">GUI App</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/GUI App</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{DC90849E-4250-4F8B-8747-7F553E39C540}</Property>
				<Property Name="Bld_userLogFile" Type="Path">../builds/GUI App/GUI App_log.txt</Property>
				<Property Name="Bld_userLogFile.pathType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_version.build" Type="Int">30</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">GUI_App.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/GUI App/GUI_App.exe</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/GUI App/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{61666519-2388-4EF2-B08E-F67BBEAAC5CF}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].Container.applyInclusion" Type="Bool">true</Property>
				<Property Name="Source[1].Container.depDestIndex" Type="Int">0</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Functions</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[1].type" Type="Str">Container</Property>
				<Property Name="Source[2].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[2].itemID" Type="Ref">/My Computer/Main_menu.vi</Property>
				<Property Name="Source[2].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[2].type" Type="Str">VI</Property>
				<Property Name="Source[3].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[3].itemID" Type="Ref">/My Computer/Call_signal_fromfile.vi</Property>
				<Property Name="Source[3].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[3].type" Type="Str">VI</Property>
				<Property Name="Source[4].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[4].itemID" Type="Ref">/My Computer/Call_signal_fromHW.vi</Property>
				<Property Name="Source[4].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[4].type" Type="Str">VI</Property>
				<Property Name="Source[5].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[5].itemID" Type="Ref">/My Computer/Old functions/New plot1_old.vi</Property>
				<Property Name="Source[5].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[5].type" Type="Str">VI</Property>
				<Property Name="Source[6].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[6].itemID" Type="Ref">/My Computer/Share_Variables.lvlib</Property>
				<Property Name="Source[6].Library.allowMissingMembers" Type="Bool">true</Property>
				<Property Name="Source[6].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[6].type" Type="Str">Library</Property>
				<Property Name="Source[7].Container.applyInclusion" Type="Bool">true</Property>
				<Property Name="Source[7].Container.depDestIndex" Type="Int">0</Property>
				<Property Name="Source[7].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[7].itemID" Type="Ref">/My Computer/TCP</Property>
				<Property Name="Source[7].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[7].type" Type="Str">Container</Property>
				<Property Name="SourceCount" Type="Int">8</Property>
				<Property Name="TgtF_companyName" Type="Str">RPTU Kaiserslautern-Landau</Property>
				<Property Name="TgtF_enableDebugging" Type="Bool">true</Property>
				<Property Name="TgtF_fileDescription" Type="Str">GUI App
The GUI application is the main interface for the user to interact with the control system. It is responsible for displaying the data, sending commands to the microcontroller, and handling errors. The GUI application is built using LabVIEW, a graphical programming language that allows for easy and intuitive development of user interfaces.</Property>
				<Property Name="TgtF_internalName" Type="Str">GUI App</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2024 RPTU Kaiserslautern-Landau</Property>
				<Property Name="TgtF_productName" Type="Str">GUI App</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{6B7D183B-7C1E-4056-8335-7620DD68DBB2}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">GUI_App.exe</Property>
				<Property Name="TgtF_versionIndependent" Type="Bool">true</Property>
			</Item>
		</Item>
	</Item>
</Project>
