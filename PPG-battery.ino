//Pin assignment
int WVPin = 0;     //Wijs Vinger pin
int BHPPin = 1;    //Bovenkant Handpalm pin
int MVHPin = 2;    //Muis van hand pin
int DPin = 3;      //Duim Pin 
int BatteryPin = 5

//Reading assignment
int WVReading;
int BHPReading;
int MVHReading;
int DReading;

//Read voltage assignment
int WVVoltage;
int BHPVoltage;
int MVHVoltage;
int DVoltage;

//Resistance calculation assignment
unsigned long WVResistance;
unsigned long BHPResistance;
unsigned long MVHResistance;
unsigned long DResistance;

//Conductance calculation assignment
float WVConductance;
float BHPConductance;
float MVHConductance;
float DConductance;

//Force calculation assignment
float WVForce;
float BHPForce;
float MVHForce;
float DForce;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //Assigning all values to their corresponding readings
  WVReading = analogRead(WVPin);
  BHPReading = analogRead(BHPPin);
  MVHReading = analogRead(MVHPin);
  DReading = analogRead(DPin);

  //Mapping the voltage
  WVVoltage = map(WVReading, 0, 1023, 0, 5000);
  BHPVoltage = map(BHPReading, 0, 1023, 0, 5000);
  MVHVoltage = map(MVHReading, 0, 1023, 0, 5000);
  DVoltage = map(DReading, 0, 1023, 0, 5000);

  //Calculating resistance
  WVResistance = 5000 - WVVoltage;
  WVResistance *= 10000;
  WVResistance /= WVVoltage;

  BHPResistance = 5000 - BHPVoltage;
  BHPResistance *= 10000;
  BHPResistance /= BHPVoltage;

  MVHResistance = 5000 - MVHVoltage;
  MVHResistance *= 10000;
  MVHResistance /= MVHVoltage;

  DResistance = 5000 - DVoltage;
  DResistance *= 10000;
  DResistance /= DVoltage;

  //Calculating Conductance
  WVConductance = 1000000;
  WVConductance /= WVResistance;

  BHPConductance = 1000000;
  BHPConductance /= BHPResistance;

  MVHConductance = 1000000;
  MVHConductance /= MVHResistance;

  DConductance = 1000000;
  DConductance /= DResistance;

  //Calculating The Force :P (Finally)
    WVForce = WVConductance / 68;
    //Serial.print("WijsVinger: ");
    //Serial.println(WVForce);

    BHPForce = BHPConductance / 68;
    //Serial.print("BovenkantHandPalm: ");
    //Serial.println(BHPForce);

    MVHForce = MVHConductance / 68;
    //Serial.print("MuisVanHand: ");
    //Serial.println(MVHForce);

    DForce = DConductance / 68;
    //Serial.print("Duim: ");
    //Serial.println(DForce);
  Serial.print("#");
  Serial.print(WVForce);
  Serial.print(" ");
  Serial.print(BHPForce);
  Serial.print(" ");
  Serial.print(MVHForce);
  Serial.print(" ");
  Serial.println(DForce); 
  Serial.print(" ");
  Serial.println(analogRead(BatteryPin) * (5.0 / 1023.0))
  delay(100);
}
