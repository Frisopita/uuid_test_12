/*
 * Ejemplo leer temperatura y humedad
 * Sensor DHT11 y ESP32s
 * Este código que me esta funcionando para realizar pruebas
 */
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Thread.h>
#include <ThreadController.h>

ThreadController controll = ThreadController();

Thread* btThread = new Thread();

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_S1_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define CHARACTERISTIC_S2_UUID "8bdf0a1a-a48e-4dc3-8bab-ad0c1f7ed218"
#define CHARACTERISTIC_S3_UUID "411fcc1c-e7a5-4a61-82fe-0004993dd1f4"
#define CHARACTERISTIC_S4_UUID "c608f523-aa19-40d1-8359-ad43409c34d7"
#define CHARACTERISTIC_S5_UUID "52294b4d-d66e-4d68-9782-1e5bb8f7ba14"
#define CHARACTERISTIC_S6_UUID "7533653f-6f0e-41fa-8fa6-9892a1904db1"
#define CHARACTERISTIC_S7_UUID "607a2edc-007d-4d51-a3a6-58fad0db3c37"
#define CHARACTERISTIC_S8_UUID "f663c0e7-d78d-466f-9b0c-408e3cc4c3d3"
#define CHARACTERISTIC_S9_UUID "778a30f8-943b-4375-b261-fb264772063c"
#define CHARACTERISTIC_S10_UUID "a8f2dbc3-c562-42d9-a094-33e4cca73118"
#define CHARACTERISTIC_S11_UUID "3c21b038-85a3-4c47-aa78-446f301dd61c"
#define CHARACTERISTIC_S12_UUID "1b0724f2-156b-41a6-8bb6-22be491731fc"
#define CHARACTERISTIC_S13_UUID "6743b155-5778-4756-b31f-34e9e8e53a9d"

BLEServer* pServer = NULL;
BLECharacteristic* pCharacteristicS1 = NULL;
BLECharacteristic* pCharacteristicS2 = NULL;
BLECharacteristic* pCharacteristicS3 = NULL;
BLECharacteristic* pCharacteristicS4 = NULL;
BLECharacteristic* pCharacteristicS5 = NULL;
BLECharacteristic* pCharacteristicS6 = NULL;
BLECharacteristic* pCharacteristicS7 = NULL;
BLECharacteristic* pCharacteristicS8 = NULL;
BLECharacteristic* pCharacteristicS9 = NULL;
BLECharacteristic* pCharacteristicS10 = NULL;
BLECharacteristic* pCharacteristicS11 = NULL;
BLECharacteristic* pCharacteristicS12 = NULL;
BLECharacteristic* pCharacteristicS13 = NULL;

bool deviceConnected = false;
bool oldDeviceConnected = false;
uint32_t value = 0;

int S1 = 120;
int S2 = 100;
int S3 = 40;
int S4 = 25;
int S5 = 35;
int S6 = 10;
int S7 = 7;
int S8 = 15;
int S9 = 50;
int S10 = 65;
int S11 = 75;
int S12 = 85;
int S13 = 0;

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      BLEDevice::startAdvertising();
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};

class MyCallbacks: public BLECharacteristicCallbacks{
  void onWrite(BLECharacteristic *pCharacteristic){
    std::string rxValue = pCharacteristic->getValue();

    if (rxValue.length()>0) {

      Serial.println("Recibiendo datos");
      Serial.print("Datos:");

      for (int i = 0; i < rxValue.length(); i++){
        Serial.print(rxValue[i]);
      }

      Serial.println();
      Serial.println("Finalizar recepción");
    }
  }
};

void setup() {
  Serial.begin(115200);
  initBT();
  
  btThread->onRun(btCallback);
  btThread->setInterval(100);

  controll.add(btThread);
}

void loop() {
// put your main code here, to run repeatedly: 
  controll.run();

     //Aumentar los valores de los sensores
     S1 = S1+1;
     S2 = S2+1;
      
      delay(5000);

      Serial.print("S1:");
      Serial.print(S1);
      Serial.print(" S2:");
      Serial.print(S2);
      Serial.print(" S3:");
      Serial.print(S3);
      Serial.print(" S4:");
      Serial.print(S4);
      Serial.print(" S5:");
      Serial.print(S5);
      Serial.print(" S6:");
      Serial.print(S6);
      Serial.print(" S7:");
      Serial.print(S7);
      Serial.print(" S8:");
      Serial.print(S8);
      Serial.print(" S9:");
      Serial.print(S9);
      Serial.print(" S10: ");
      Serial.print(S10);
      Serial.print(" S11:");
      Serial.print(S11);
      Serial.print(" S12:");
      Serial.print(S12);
      Serial.print(" S13:");
      Serial.print(S13);
      Serial.print('\n');
  
}

void btCallback(){
  // notify changed value
    if (deviceConnected) {

      String strS1 = "";
      strS1 += S1;
      String strS2 = "";
      strS2 += S2;
      String strS3 = "";
      strS3 += S3;
      String strS4 = "";
      strS4 += S4;
      String strS5 = "";
      strS5 += S5;
      String strS6 = "";
      strS6 += S6;
      String strS7 = "";
      strS7 += S7;
      String strS8 = "";
      strS8 += S8;
      String strS9 = "";
      strS9 += S9;
      String strS10 = "";
      strS10 += S10;
      String strS11 = "";
      strS11 += S11;
      String strS12 = "";
      strS12 += S12;
      String strS13 = "";
      strS12 += S13;
      
      Serial.print(strS1);
      Serial.print(strS2);
      Serial.print(strS3);
      Serial.print(strS4);
      Serial.print(strS5);
      Serial.print(strS6);
      Serial.print(strS7);
      Serial.print(strS8);
      Serial.print(strS9);
      Serial.print(strS10);
      Serial.print(strS11);
      Serial.print(strS12);
      Serial.print(strS13);
      
      pCharacteristicS1->setValue((char*)strS1.c_str());
      pCharacteristicS1->notify();

      pCharacteristicS2->setValue((char*)strS2.c_str());
      pCharacteristicS2->notify();

      pCharacteristicS3->setValue((char*)strS3.c_str());
      pCharacteristicS3->notify();

      pCharacteristicS4->setValue((char*)strS4.c_str());
      pCharacteristicS4->notify();

      pCharacteristicS5->setValue((char*)strS5.c_str());
      pCharacteristicS5->notify();

      pCharacteristicS6->setValue((char*)strS6.c_str());
      pCharacteristicS6->notify();

      pCharacteristicS7->setValue((char*)strS7.c_str());
      pCharacteristicS7->notify();

      pCharacteristicS8->setValue((char*)strS8.c_str());
      pCharacteristicS8->notify();

      pCharacteristicS9->setValue((char*)strS9.c_str());
      pCharacteristicS9->notify();

      pCharacteristicS10->setValue((char*)strS10.c_str());
      pCharacteristicS10->notify();

      pCharacteristicS11->setValue((char*)strS11.c_str());
      pCharacteristicS11->notify();

      pCharacteristicS12->setValue((char*)strS12.c_str());
      pCharacteristicS12->notify();
    
      pCharacteristicS13->setValue((char*)strS13.c_str());
      pCharacteristicS13->notify();

    }
    // disconnecting
    if (!deviceConnected && oldDeviceConnected) {
        //delay(500); // give the bluetooth stack the chance to get things ready
        pServer->startAdvertising(); // restart advertising
        Serial.println("start advertising");
        oldDeviceConnected = deviceConnected;
    }
    // connecting
    if (deviceConnected && !oldDeviceConnected) {
        // do stuff here on connecting
        oldDeviceConnected = deviceConnected;
    }
}


void initBT(){
  // Create the BLE Device
  BLEDevice::init("ESP32 Sopita");

  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(BLEUUID(SERVICE_UUID), 50, 0);

  // Create a BLE Characteristic
  pCharacteristicS1 = pService->createCharacteristic(
                      CHARACTERISTIC_S1_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  
  pCharacteristicS2 = pService->createCharacteristic(
                      CHARACTERISTIC_S2_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  
  pCharacteristicS3 = pService->createCharacteristic(
                      CHARACTERISTIC_S3_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  
  pCharacteristicS4 = pService->createCharacteristic(
                      CHARACTERISTIC_S4_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  
  pCharacteristicS5 = pService->createCharacteristic(
                      CHARACTERISTIC_S5_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  
  pCharacteristicS6 = pService->createCharacteristic(
                      CHARACTERISTIC_S6_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  
  pCharacteristicS7 = pService->createCharacteristic(
                      CHARACTERISTIC_S7_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  
  pCharacteristicS8 = pService->createCharacteristic(
                      CHARACTERISTIC_S8_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  
  pCharacteristicS9 = pService->createCharacteristic(
                      CHARACTERISTIC_S9_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  
  pCharacteristicS10 = pService->createCharacteristic(
                      CHARACTERISTIC_S10_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  
  pCharacteristicS11 = pService->createCharacteristic(
                      CHARACTERISTIC_S11_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  
  pCharacteristicS12 = pService->createCharacteristic(
                      CHARACTERISTIC_S12_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  
  pCharacteristicS13 = pService->createCharacteristic(
                      CHARACTERISTIC_S13_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  
  pCharacteristicS1->setCallbacks(new MyCallbacks());
  pCharacteristicS2->setCallbacks(new MyCallbacks());
  pCharacteristicS3->setCallbacks(new MyCallbacks());
  pCharacteristicS4->setCallbacks(new MyCallbacks());
  pCharacteristicS5->setCallbacks(new MyCallbacks());
  pCharacteristicS6->setCallbacks(new MyCallbacks());
  pCharacteristicS7->setCallbacks(new MyCallbacks());
  pCharacteristicS8->setCallbacks(new MyCallbacks());
  pCharacteristicS9->setCallbacks(new MyCallbacks());
  pCharacteristicS10->setCallbacks(new MyCallbacks());
  pCharacteristicS11->setCallbacks(new MyCallbacks());
  pCharacteristicS12->setCallbacks(new MyCallbacks());
  pCharacteristicS13->setCallbacks(new MyCallbacks());
  // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.client_characteristic_configuration.xml
  // Create a BLE Descriptorn
  pCharacteristicS1->addDescriptor(new BLE2902());
  pCharacteristicS2->addDescriptor(new BLE2902());
  pCharacteristicS3->addDescriptor(new BLE2902());
  pCharacteristicS4->addDescriptor(new BLE2902());
  pCharacteristicS5->addDescriptor(new BLE2902());
  pCharacteristicS6->addDescriptor(new BLE2902());
  pCharacteristicS7->addDescriptor(new BLE2902());
  pCharacteristicS8->addDescriptor(new BLE2902());
  pCharacteristicS9->addDescriptor(new BLE2902());
  pCharacteristicS10->addDescriptor(new BLE2902());
  pCharacteristicS11->addDescriptor(new BLE2902());
  pCharacteristicS12->addDescriptor(new BLE2902());
  pCharacteristicS13->addDescriptor(new BLE2902());
  // Start the service
  pService->start();

  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x0);  // set value to 0x00 to not advertise this parameter
  BLEDevice::startAdvertising();
  Serial.println("Waiting a client connection to notify...");
  
}