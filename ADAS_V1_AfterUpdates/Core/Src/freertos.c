/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "motor_Interf.h"
#include "usart.h"
#include "tim.h"
#include "AB_Interf.h"
#include "FCA_Interf.h"
#include "FCW_Interf.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define MOVE_FORWARD		'f'
#define MOVE_BACKWARD		'b'
#define MOVE_RIGHT			'r'
#define MOVE_LEFT			'l'
#define STOP				's'


/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
uint8_t motion_Direction =0;
uint8_t motion_PWM=0;
uint8_t distance=255;
uint8_t ultrasonicReadsVariable;
uint8_t ultrasoncForwordReading;
uint8_t ultrasoncRightReading;
uint8_t ultrasoncLeftReading;

extern uint8_t g_key;
extern uint8_t g_Action ;

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId myTask02Handle;
osThreadId myTask04Handle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void T1_FCW_FCA_BA(void const * argument);
void T3_MotionDrive(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityIdle, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of myTask02 */
  osThreadDef(myTask02, T1_FCW_FCA_BA, osPriorityHigh, 0, 128);
  myTask02Handle = osThreadCreate(osThread(myTask02), NULL);

  /* definition and creation of myTask04 */
  osThreadDef(myTask04, T3_MotionDrive, osPriorityRealtime, 0, 128);
  myTask04Handle = osThreadCreate(osThread(myTask04), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_T1_FCW_FCA_BA */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_T1_FCW_FCA_BA */
void T1_FCW_FCA_BA(void const * argument)
{
  /* USER CODE BEGIN T1_FCW_FCA_BA */
  /* Infinite loop */
  for(;;)
  {/*TAKE_Warning_Semaphore than take decision wich system to be activated (FCW or FCA or AB)*/
	  //	  	if ( (distance < AUTOMATIC_BRAKE_DISTANCE) && (ultrasonicRight_Read < WARRNING_DISTANCE) &&  (ultrasonicLeft_Read < WARRNING_DISTANCE)) {
	  //	  		AutomaticBrake();
	  //	  	} else if ((distance < FORWARD_COLISSION_AVOIDANCE_DISTANCE) && (ultrasonicRightRead <= WARRNING_DISTANCE) && (ultrasonicLeftRead > WARRNING_DISTANCE)) {
	  //			FCA_LeftON();
	  //	  	}
	  //	  	else if ((distance < FORWARD_COLISSION_AVOIDANCE_DISTANCE) && (ultrasonicRightRead > WARRNING_DISTANCE) && (ultrasonicLeftRead <= WARRNING_DISTANCE)) {
	  //			FCA_RightON();
	  //	  	} else if(distance<WARRNING_DISTANCE){
	  //	  		FCW_WarrningON();
	  //	  	}
	  //	  	else
	  //	  	{
	  //	  		/*Do nothing*/
	  //	  	}
    osDelay(1);
  }
  /* USER CODE END T1_FCW_FCA_BA */
}

/* USER CODE BEGIN Header_T3_MotionDrive */
/**
* @brief Function implementing the myTask04 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_T3_MotionDrive */
void T3_MotionDrive(void const * argument)
{
  /* USER CODE BEGIN T3_MotionDrive */
	  /* Infinite loop */
	motion_Direction = 's';
	motion_PWM =0;
  for(;;)
  {
	  /*Take Bluetooth_Semaphore that was given by the UART_Interrupt receiving input from user
	 	   * then its allowed to control the car via app controller */
	 	  /* if event receive from Bluetooth is given by interrupt callback function of UART*/
	 		switch (motion_Direction) {
	 	  	case MOVE_FORWARD:
	 	  		Forward();
	 	  		break;
	 	  	case MOVE_BACKWARD:
	 	  		Backward();
	 	  		break;
	 	  	case MOVE_LEFT:
	 	  		Left();
	 	  		break;
	 	  	case MOVE_RIGHT:
	 	  		Right();
	 	  		break;
	 	  	case STOP:
	 	  		Stop();
	 	  		break;
	 	  	default:
	 	  		break;
	 	  	}
	 		/*update the PWM value*/
	 		//sConfigOC.Pulse = motion_PWM;
	 		__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,motion_PWM); //TIM1-> CCR1 = motion_PWM;


//	 	  }

    osDelay(1);
  }
  /* USER CODE END T3_MotionDrive */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	if(g_key<50){
		motion_PWM=g_key;
	}
	else{
		motion_Direction=g_key;
	}
	HAL_UART_Receive_IT(&huart1, &g_key,1);
}

/* USER CODE END Application */

