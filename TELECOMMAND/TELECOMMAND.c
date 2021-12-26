#include "TELECOMMAND.h"
#include "string.h"
#include "stdlib.h"

unsigned char CCSDSTeleCommandProtocolPHeadrGN (unsigned char Frame_Version_Number,Bypass_Flag BF ,Control_Command_Flag CF,
                                        unsigned short Spacecraft_Identifier,unsigned short Virtual_Channel_Identifier,unsigned short Frame_Length,unsigned char Frame_Sequence_Number,Primarry_Hrader * ph)
										{
											
										if (ph != NULL)
											{
												ph->Primary_Header_Fields.Transfer_Frame_Version_Number=Frame_Version_Number;
												ph->Primary_Header_Fields.Bypass_Flag=BF;
												ph->Primary_Header_Fields.Control_Command_Flag=CF;
												ph->Primary_Header_Fields.Spacecraft_Identifier=Spacecraft_Identifier;
												ph->Primary_Header_Fields.Virtual_Channel_Identifier=Virtual_Channel_Identifier;
												ph->Primary_Header_Fields.Frame_Length=Frame_Length;
												ph->Primary_Header_Fields.Frame_Sequence_Number=Frame_Sequence_Number;

											}
											else
											{

											return -1;

											}
											ph = (Primarry_Hrader*) malloc(5);	
											
										}
										
unsigned char  TELECOMMANDFRAMConstruction (Primarry_Hrader * ph,unsigned char *Data,int Data_Length,unsigned char * Data_output,unsigned short CRC)
										{

										if (ph != NULL)
											{
												
												Data_output = realloc(Data_output,sizeof(5+Data_Length+2));
												memcpy(Data_output,ph,5);
												memcpy(Data_output+5,Data,Data_Length);
												memcpy(Data_output+5+Data_Length,CRC,2);
											}
											else
											{

											return -1;

											}

										
										}