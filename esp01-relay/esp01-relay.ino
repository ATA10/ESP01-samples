#include <ESP8266WiFi.h>

// WiFi bilgilerinizi girin
const char* ssid = "AAA";       // WiFi ağ adı
const char* password = "attATT112.."; // WiFi şifresi

// LED pinleri
const int led1 = 2;  // GPIO2
const int led2 = 0;  // GPIO0

// Web sunucusu oluştur
WiFiServer server(80);

void setup() {
  // Seri iletişimi başlat
  Serial.begin(115200);
  delay(10);

  // LED pinlerini çıkış olarak ayarla
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);

  // WiFi bağlantısını başlat
  Serial.println();
  Serial.print("WiFi ağına bağlanıyor: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi bağlantısı başarılı!");

  // Web sunucusunu başlat
  server.begin();
  Serial.println("Web sunucusu başlatıldı.");

  // IP adresini yazdır
  Serial.print("Web arayüzüne erişmek için: http://");
  Serial.println(WiFi.localIP());
}

void loop() {
  // İstemci bağlantısını kontrol et
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // İstemciden gelen isteği oku
  Serial.println("Yeni bir istemci bağlandı!");
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // LED kontrolü
  if (request.indexOf("GET /LED1/ON") != -1) {
    digitalWrite(led1, HIGH);
  } else if (request.indexOf("GET /LED1/OFF") != -1) {
    digitalWrite(led1, LOW);
  } else if (request.indexOf("GET /LED2/ON") != -1) {
    digitalWrite(led2, HIGH);
  } else if (request.indexOf("GET /LED2/OFF") != -1) {
    digitalWrite(led2, LOW);
  }

  // Web sayfasını oluştur
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"></head>");
  client.println("<body>");
  client.println("<h1>ESP-01 LED Kontrol</h1>");
  client.println("<p>LED 1: <a href=\"/LED1/ON\"><button>ON</button></a> <a href=\"/LED1/OFF\"><button>OFF</button></a></p>");
  client.println("<p>LED 2: <a href=\"/LED2/ON\"><button>ON</button></a> <a href=\"/LED2/OFF\"><button>OFF</button></a></p>");
  client.println("</body>");
  client.println("</html>");

  delay(1);
  Serial.println("İstemci bağlantısı kesildi.");
  Serial.println("");
}
