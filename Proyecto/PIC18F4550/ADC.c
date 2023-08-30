/************************************************************************************************
Company:
Microside Technology Inc.
Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/

/*
---------------------------------------------------------------------------
Implementar una lectura analógica de un potenciómetro y desplegar el valor
en 8 LEDs
---------------------------------------------------------------------------
*/

#include <18F4550.h>                           // Incluye el microcontrolador con el que se va a trabajar 
#DEVICE ADC = 8                                // Configura el ADC a 8 bits
#use delay( clock=48Mhz, crystal )             // Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build( reset=0x02000, interrupt=0x02008 )     // Asigna los vectores de reset e interrupción para la versión con bootloader
#org 0x0000,0x1FFF {}                          // Reserva espacio en memoria para el bootloader
 
int ValorPot;                                  // Variable para almacenar el valor leído del ADC

void main ( void ) {
   setup_oscillator( OSC_8MHZ );               // Configura oscilador interno
   set_tris_b( 0x00 );                         // Configura todo el puerto B como salidas digitales
   setup_adc_ports( AN0 );                     // Configura solo el puerto A0 como entrada analógica
   setup_adc( ADC_CLOCK_DIV_8 );               // Configura oscilador para la conversión

   while ( 1 ) {
      set_adc_channel( 0 );                    // Selecciona el canal 0 para la conversión
      ValorPot = read_adc();                   // Lee el valor del ADC y lo guarda en  la variable

      if ( ValorPot <= 28 ) {                  // Compara el valor de el ADC
         output_b( 0b00000000 );               // Activa los leds
      } else if ( ValorPot <= 56 ) {
         output_b( 0b00000001 ); 
      } else if ( ValorPot <= 84 ) {
         output_b( 0b00000011 ); 
      } else if ( ValorPot <= 112 ) {
         output_b( 0b00000111 );
      } else if ( ValorPot <= 140 ) {
         output_b( 0b00001111 ); 
      } else if ( ValorPot <= 168 ) {
         output_b( 0b00011111 ); 
      } else if ( ValorPot <= 196 ) {
         output_b( 0b00111111 ); 
      } else if ( ValorPot <= 252 ) {
         output_b( 0b01111111 ); 
      } else if ( ValorPot <= 255 ) {
         output_b( 0b11111111 ); 
      }
   }
}