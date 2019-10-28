* Hacer la conexion a la protoboard (no poner el modulo bluetooth aun)
Abrir el programa con la configuración
Cambiar el nombre para renombrar nuestro módulo
Poner clave que desea use este modulo
Cargar el programa a la placa arduino

Una vez cargado se dispone de 15 segundos para pinchar el módulo Bluetooth a la protoboard, y automaticamente despues se verá parpadear distinto durante un segundo el led de la plaquita Bluetooth, lo que indicará que está trabajando y cambiando el nombre.

A continuación el led volverá a parpadear constantemente intermitente (estado de espera a activacion)

 */
char nombre[10] = "poner_nombre"; //El nuevo nombre del modulo
char password[10] = "poner_clave"; //la nueva clave para vincular el modulo con Android.
char baud = '4'; //4 = 9600 baud
 
void setup()
{
  Serial.begin(9600);
   
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  delay(15000); //Esperar 15 segundos para conectar el modulo
   
  Serial.print("AT"); //Iniciar la configuracion
  delay(1000);
   
  Serial.print("AT+NAME"); Serial.print(nombre); //Cambiar el nombre
  delay(1000);
   
  Serial.print("AT+PIN"); Serial.print(password); //Cambiar contraseña
  delay(1000);   
   
  Serial.print("AT+BAUD"); Serial.print(baud); //Cambiar baudios
  delay(1000);
   
  digitalWrite(13, HIGH);
}
 
void loop(){}
