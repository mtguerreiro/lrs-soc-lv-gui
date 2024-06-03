## Waveform Graph
**Description**: This window plot displays the signals in the application. The user can select the signals to be displayed in the graph.

´´´mermaid
graph LR

    subgraph GUI_App 
    A[Main_menu.vi] ==> B[Window_plot.vi]
    B -.->|Call| C[Call_signal_fromHW.vi]
    B -.->|Call| D[Call_signal_fromfile.vi]
    A --> E[(Shared_Variables.lvlib)]
    E --> C
    C -->|Signal data| B
    D -->|Signal data| B
    end
    A <-->|TCP IP communication| A1
    F[CSV file] --> D
    subgraph Hardware
        A1[Microcontroller]
    end
´´´