'!TITLE "Zimmer Gripper Header"
' ***************************************************************************************
' * RC8 Driver For Zimmer Gripper 6000s Series											*
' *																						*
' * Author: Carlos A. Lopez																*
' * Date: 10/5/2017																		*
' * Version: 0.7 Debug 																	*
' *																						*
' * If you have any issues with this driver 											*
' * please contact us at: 																*
' * 																					*
' *	< robotics_applications@densodrive.com >											*
' *																						*
' * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, *	
' * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 		*
' * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 	*
' * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 	*
' * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 		*
' * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.								*
' *																						*
' ***************************************************************************************

'----------------------------------------------------------------------------------------
' Timeout(s) & Flags
'----------------------------------------------------------------------------------------
#Define GLOBAL_TIMEOUT	30000
#Define DEBUG_MODE		1

'----------------------------------------------------------------------------------------
' Driver Files
'----------------------------------------------------------------------------------------

#Include "Variant.h"
#Include "Zimmer.pcs"
#Include "Zimmer_IR.pcs"
#Include "Zimmer_HR.pcs"
#Include "Denso_CAO.pcs"

'----------------------------------------------------------------------------------------
' Application Functions (Used mainly for interfacing with the zimmer gripper)
'----------------------------------------------------------------------------------------

'Function ZConnect(String, Integer, Integer, Integer) As Variant
'Function ZIdle(Variant) As Integer
'Function ZGripperReset(Variant) As Integer
'Function ZResetDirFlag(Variant) As Integer
'Function ZMotor(Variant, Integer) As Integer
'Function ZHome(Variant) As Integer
'Function ZJog(Variant, Integer) As Integer
'Function ZOpen(Variant) As Integer
'Function ZClose(Variant) As Integer
'Function ZSetMotionParam(Variant, Variant, Variant, Variant, Variant, Variant,_
'						 Variant, Variant, Variant) As Integer
'Function ZTeachPos(Variant) As Integer
'Function ZSaveWorkRecipe(Variant, Variant) As Integer
'Function ZLoadWorkRecipe(Variant, Variant) As Integer

'----------------------------------------------------------------------------------------
' IO-Link Inputs To Modbus Map (Right now only available for 6000s) 
'----------------------------------------------------------------------------------------

' (Status Word)

'Function ZGet_Status(Variant) As Integer					(16-bit)
'Function ZGet_HomePoseOK_Status(Variant) As Integer		(1-bit)	
'Function ZGet_MotorOn_Status(Variant) As Integer			(1-bit)	
'Function ZGet_InMotion_Status(Variant) As Integer			(1-bit)	
'Function ZGet_CompleteMovement_Status(Variant) As Integer	(1-bit)	
'Function ZGet_NJogModeActive_Status(Variant) As Integer	(1-bit)	
'Function ZGet_PJogModeActive_Status(Variant) As Integer	(1-bit)	
'Function ZGet_GripCtrlSysActive_Status(Variant) As Integer	(1-bit)	
'Function ZGet_CtrlError_Status(Variant) As Integer			(1-bit)	
'Function ZGet_BasePose_Status(Variant) As Integer			(1-bit)	
'Function ZGet_TeachPose_Status(Variant) As Integer			(1-bit)	
'Function ZGet_WorkPose_Status(Variant) As Integer			(1-bit)	
'Function ZGet_UndefPose_Status(Variant) As Integer			(1-bit)	
'Function ZGet_DataTransferOK_Status(Variant) As Integer	(1-bit)	
'Function ZGet_CtrlWordx100_Status(Variant) As Integer		(1-bit)	
'Function ZGet_CtrlWordx200_Status(Variant) As Integer		(1-bit)	
'Function ZGet_Error_Status(Variant) As Integer				(1-bit)	

' (Diagnostic Word)

'Function ZGet_Diagnostics(Variant) As Integer				(16-bit)

' (Actual Position Word)

'Function ZGet_CurPos(Variant) As Single					(1-bit)

'----------------------------------------------------------------------------------------
' IO-Link Outputs (Read) to Modbus Map (Right now only available for 6000s) 
'----------------------------------------------------------------------------------------

' (Control Word)
'Function ZGet_CtrlWord(Variant) As Integer			(16-bit)

' (Device Mode / Workpiece No Word)
'Function ZGet_DeviceMode(Variant) As Integer		(8-bit)
'Function ZGet_WorkpieceNo(Variant) As Integer		(8-bit)

' (Reservec / Position Tolerance Word)
'Function ZGet_PoseTolerance(Variant) As Integer	(8-bit)

' (Grip Force / Drive Velocity Word)
'Function ZGet_GripForce(Variant) As Integer		(8-bit)
'Function ZGet_DriveVelocity(Variant) As Integer	(8-bit)

' (Base Position Word)
'Function ZGet_BasePose(Variant) As Single			(16-bit)

' (Shift Position Word)
'Function ZGet_ShiftPose(Variant) As Single			(16-bit)

' (Teach Position Word)
'Function ZGet_TeachPose(Variant) As Single			(16-bit)

' (Work Position Word)
'Function ZGet_WorkPose(Variant) As Single			(16-bit)

'----------------------------------------------------------------------------------------
' IO-Link Outputs (Write) to Modbus Map (Right now only available for 6000s)
'----------------------------------------------------------------------------------------

' (Control Word)
'Function ZSet_CtrlWord(Variant, Variant) As Integer

' (Device Mode / Workpiece No Word)
'Function ZSet_DeviceMode(Variant, Variant) As Integer
'Function ZSet_WorkpieceNo(Variant, Variant) As Integer

' (Reservec / Position Tolerance Word)
'Function ZSet_PoseTolerance(Variant, Variant) As Integer

' (Grip Force / Drive Velocity Word)
'Function ZSet_GripForce(Variant, Variant) As Integer
'Function ZSet_DriveVelocity(Variant, Variant) As Integer

' (Base Position Word)
'Function ZSet_BasePose(Variant, Variant) As Integer 

' (Shift Position Word)
'Function ZSet_ShiftPose(Variant, Variant) As Integer 

' (Teach Position Word)
'Function ZSet_TeachPose(Variant, Variant) As Integer 

' (Work Position Word)
'Function ZSet_WorkPose(Variant, Variant) As Integer 

