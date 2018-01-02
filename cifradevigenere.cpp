#include <iostream>
#include <string>
using namespace std;
 
class Vigenere  //criação da classe pública
{
public:
  string chave;
 
  Vigenere(string chave){
    for(int i = 0; i < chave.size(); ++i)
    {
      if(chave[i] >= 'A' && chave[i] <= 'Z')
        this->chave += chave[i];
      else if(chave[i] >= 'a' && chave[i] <= 'z')
        this->chave += chave[i] + 'A' - 'a';
    }
  }
 
  string encriptar(string texto){ //metodo onde vai encriptar o texto claro
    string out;
 
    for(int i = 0, j = 0; i < texto.length(); ++i){
      char c = texto[i];
 
      if(c >= 'a' && c <= 'z') 
        c += 'A' - 'a';
      else if(c < 'A' || c > 'Z')
        continue;
      
      out += (c + chave[j] - 2*'A') % 26 + 'A'; 
      j = (j + 1) % chave.length();
    }
 
    return out;
  }
 
  string decriptar(string texto){ //método que vai decriptar o texto claro
    string out;
 
    for(int i = 0, j = 0; i < texto.length(); ++i){
      char c = texto[i];
 
      if(c >= 'a' && c <= 'z')
        c += 'A' - 'a';
      else if(c < 'A' || c > 'Z')
        continue;
 
      out += (c - chave[j] + 26) % 26 + 'A'; 
      j = (j + 1) % chave.length();
    }
 
    return out;
  }
};
 
int main(){ //metodo main onde a classe é chamada e é criada os objetos para a chamada dos métodos

   string texto_claro; //texto claro (mensagem onde a ser codificada)
   string txtchave; //chave usada para encriptar o textoo claro

   cout<<"Digite o texto Claro (em letras minusculas e sem espacos)"<<endl;
   cin>>texto_claro;
   cout<<endl;
   cout<<"Digite a chave (palavra curta sem espaços e acentos)"<<endl;
   cin>>txtchave;
   cout<<endl;

  Vigenere cifra(txtchave); //criação do objeto da classe Vigenere
 
  string encriptar = cifra.encriptar(texto_claro);
  string decriptar = cifra.decriptar(encriptar);
 
 // printa na tela o texto-claro encriptado
  cout << "Texto-Claro:" << texto_claro << endl;
  cout << "Chave:" << txtchave << endl; 
  cout << "Encriptado: " << encriptar << endl;
  cout << "decriptado: " << decriptar << endl;
}