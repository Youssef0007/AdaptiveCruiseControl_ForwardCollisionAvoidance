# AdaptiveCruiseControl_ForwardCollisionAvoidance

This repo contains the implementation of two ADAS Features (Adaptive Cruise Control and Forward Collision Avoidance) on an ARM Cortex-M3 microcontroller (STM32F103C8T6) using a Real-Time Operating System(RTOS). 

## Project Machine State Diagram 

![Project Machine State](https://github.com/SeifAhmed25/AdaptiveCruiseControl_ForwardCollisionAvoidance/assets/64741466/50f93f94-153c-411f-a04a-53435cbd0cc4)

## Reqiurements 

This Project is mainly divided into 3 Levels 

### Level 1 
- Implementing the ADAS features (Cruise control - forward collision avoidance).
- Implementing the System using FreeRTOS.
- Target: 1 * (STM32F103C8T6).   

### Level 2 
- Dividing the System Tasks among 2 STM boards.
- The System will be communicating via CAN BUS.
- Targets: 2 * (STM32F103C8T6).  

### Level 3
- Implementing the FOTA (Firmware Over The Air) Software using ESP32 NodeMCU.
- Uploading new ADAS features and releases using FOTA. 
- Targets: 2 * (STM32F103C8T6) + ESP32.
