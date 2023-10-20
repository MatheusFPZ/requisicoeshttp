 int elementoDesejado = 2;
 int elementoAserExcluido = 3;



//inserir 3 valores
void fazerSolicitacaoPOST(String jsonData) {
  // Crie uma instância do objeto HTTPClient
  HTTPClient http;

  // Configure a URL para a solicitação POST
  http.begin("http://192.168.0.109:3000");

  // Defina o cabeçalho para indicar que é uma solicitação POST com dados JSON
  http.addHeader("Content-Type", "application/json");

  // Faça a solicitação POST com os dados JSON
  int httpResponseCode = http.POST(jsonData);

  // Verifique a resposta do servidor
  if (httpResponseCode > 0) {
    Serial.print("Solicitação POST bem-sucedida. Código de resposta: ");
    Serial.println(httpResponseCode);
    String response = http.getString();
    Serial.println("Resposta do servidor:");
    Serial.println(response);
  } else {
    Serial.print("Erro na solicitação POST. Código de resposta: ");
    Serial.println(httpResponseCode);
  }

  // Libere os recursos
  http.end();
}

 

//consultar, alterar, e consultar
void fazerSolicitacaoGET() {
  // Crie uma instância do objeto HTTPClient
        HTTPClient http;
    
  // Configure a URL para a solicitação GET
  http.begin("http://192.168.0.1:3000/"+ String(elementoDesejado));

  // Faça a solicitação GET
  int httpResponseCode = http.GET();

  // Verifique a resposta do servidor
  if (httpResponseCode > 0) {
    elementoDesejado += 2;
    Serial.print("Solicitação GET bem-sucedida. Código de resposta: ");
    Serial.println(httpResponseCode);
    Serial.println("Resposta do servidor:");

    delay(10000);
    
    // Defina o cabeçalho para indicar que é uma solicitação PATCH
  http.addHeader("Content-Type", "application/json");

  // Crie um JSON com os campos que você deseja atualizar
  String jsonData = "{\"modelo\": \"360z\"}";
                    

  // Faça a solicitação PATCH com os dados JSON
  int httpResponseCode = http.PATCH(jsonData);

  // Verifique a resposta do servidor
  if (httpResponseCode > 0) {
    Serial.print("Solicitação PATCH bem-sucedida. Código de resposta: ");
    Serial.println(httpResponseCode);
    String response = http.getString();
    Serial.println("Resposta do servidor:");

    delay(10000);

    //consultar novamente
    int httpResponseCode2 = http.GET();


  } else {
    Serial.print("Erro na solicitação PATCH. Código de resposta: ");
    Serial.println(httpResponseCode);
  }




    } else {
    Serial.print("Erro na solicitação GET. Código de resposta: ");
    Serial.println(httpResponseCode);
  }

  // Libere os recursos
  http.end();
}


//deletar

void deletarterceiro(){
  

  HTTPClient http;
    
  // Configure a URL para a solicitação GET
  http.begin("http://192.168.0.1:3000/"+ String(elementoAserExcluido));
  int httpResponseCode = http.DELETE();

  // Verifique a resposta do servidor
  if (httpResponseCode > 0) {
    elementoAserExcluido += 3;
    Serial.print("Solicitação DELETE bem-sucedida. Código de resposta: ");
    Serial.println(httpResponseCode);
  } else {
    Serial.print("Erro na solicitação DELETE. Código de resposta: ");
    Serial.println(httpResponseCode);
  }

  // Libere os recursos
  http.end();

  // Aguarde um intervalo entre as solicitações (por exemplo, 1 minuto)
  
}


//consultar tudo
void getAll(){
        HTTPClient http;
    
  // Configure a URL para a solicitação GET
  http.begin("http://192.168.0.1:3000/");
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    elementoDesejado += 2;
    Serial.print("Solicitação GET bem-sucedida. Código de resposta: ");
    Serial.println(httpResponseCode);
    Serial.println("Resposta do servidor:");

}else {
    Serial.print("Erro na solicitação GET. Código de resposta: ");
    Serial.println(httpResponseCode);
  }

  // Libere os recursos
  http.end();
}




void loop(void) {   
    String jsonData1 = "{\"velocidade_maxima\": 200, \"modelo\": \"silvia\", \"fabricante\": \"nissan\", \"cor\": \"Vermelho\", \"ano\": \"1999-01-01\"}";
    String jsonData2 = "{\"velocidade_maxima\": 200, \"modelo\": \"350z\", \"fabricante\": \"nissan\", \"cor\": \"Vermelho\", \"ano\": \"1999-01-01\"}";
    String jsonData3 = "{\"velocidade_maxima\": 200, \"modelo\": \"skyline\", \"fabricante\": \"nissan\", \"cor\": \"Vermelho\", \"ano\": \"1999-01-01\"}";


  // Chame a função para fazer as solicitações POST
  fazerSolicitacaoPOST(jsonData1);
  fazerSolicitacaoPOST(jsonData2);
  fazerSolicitacaoPOST(jsonData3);

  delay(10000);

  fazerSolicitacaoGET();

  delay(10000);

  deletarterceiro();
  
  delay(10000);

  getAll();

  delay(10000);//dar o delay de 10s
  
}

 

