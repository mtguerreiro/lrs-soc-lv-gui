## Introduction
This document outlines the significant changes made to the naming conventions within our project. The primary objective of these changes is to enhance readability, maintainability, and consistency across our codebase.
The changes span across various components of our project, including VI, Functions, TCP Client, and Variables. Each section in this document corresponds to these components and provides a detailed overview of the old names, the new names, and a brief description of their functionalities.
By standardizing our naming conventions, we aim to create a more intuitive and user-friendly environment for both our team and any future contributors. This will not only simplify the process of understanding the code but also make it easier to debug, test, and enhance the project in the future.
Please refer to the table of contents for easy navigation through the document.

## Overview
The GUI application is the main interface for the user to interact with the control system. It is responsible for displaying the data, sending commands to the microcontroller, and handling errors. The GUI application is built using LabVIEW, a graphical programming language that allows for easy and intuitive development of user interfaces.

## Purpose
The purpose of this document is to provide a comprehensive overview of the changes made to the naming conventions within our project. This document is intended for the use of our team members and any future contributors to the project. It is designed to provide a clear understanding of the old and new names, as well as a brief description of their functionalities.

## Scope
The scope of this document covers the changes made to the naming conventions within the GUI application. The changes are categorized into different sections based on the components of the GUI application, including VI, Functions, TCP Client, and Variables. Each section provides a detailed overview of the old and new names, along with a brief description of their functionalities.

## Control System
The control system is in base of the LabVIEW software, which is a system-design platform and development environment for a visual programming language from National Instruments. It is commonly used for data acquisition, instrument control, and industrial automation on a variety of platforms including Microsoft Windows, various versions of UNIX, Linux, and macOS.%


```mermaid
graph LR
    
    A3[GUI_Labview] <-->|ref. meas switches| F
    subgraph F["Controller microcontroller/FPGA"]
    A[Power converter control]
    B[Cooling control]
    C["Trace(memory)"] 
    end

    F <-->|meas switches| A1[Actuator 1]
    F <-->|meas switches| A2[Actuator 2]
        
```

```mermaid
graph TB
    
    subgraph F["Memory(RAM)"]
    A["Trace 1 (controller 1)"]
    B["Trace 2 (temperature)"]
    end

        
```
