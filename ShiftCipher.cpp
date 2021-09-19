/*
Nama      : Marvin Luckianto
NPM       : 140810190043
Kelas     : Kriptografi A
Deskripsi : Program enkripsi dan dekripsi Shift Cipher
*/

#include <bits/stdc++.h>
using namespace std;
//
// Convert plain text to cipher text using shift cipher
string encrypt(string plain_text, int key)
{
  string cipher_text = "";
  for (int i = 0; i < plain_text.size(); i++)
  {
    // If the character is a capital letter
    if (isupper(plain_text[i]))
    {
      cipher_text += char(int(plain_text[i] + key - 65) % 26 + 65);
    }
    // If the character is not a capital letter
    if (islower(plain_text[i]))
    {
      cipher_text += char(int(plain_text[i] + key - 97) % 26 + 97);
    }
    // If the character is not a letter
    else
    {
      cipher_text += char(int(plain_text[i]));
    }
  }
  return cipher_text;
}

// Convert cipher text to plain text using shift cipher
string decrypt(string cipher_text, int key)
{
  string plain_text = "";
  for (int i = 0; i < cipher_text.size(); i++)
  {
    // If the character is a capital letter
    if (isupper(cipher_text[i]))
    {
      plain_text += char((int(cipher_text[i] - key - 65) % 26 + 26) % 26 + 65);
    }
    // If the character is not a capital letter
    if (islower(cipher_text[i]))
    {
      plain_text += char((int(cipher_text[i] - key - 97) % 26 + 26) % 26 + 97);
    }
    // If the character is not a letter
    else
    {
      plain_text += char(int(cipher_text[i]));
    }
  }
  return plain_text;
}

int main()
{
  bool isLoop = true;
  char opt;
  // loop until user input "n" or "N"
  while (isLoop == true)
  {
    string plain_text;
    cout << "Enter plain text: ";

    getline(cin, plain_text);
    int key;
    cout << "Enter key: ";
    cin >> key;

    string cipher_text = encrypt(plain_text, key);

    cout << "\nHasil Enkripsi: " << cipher_text;
    cout << "\nHasil Dekripsi: " << decrypt(cipher_text, key);
    do
    {
      cout << "\nApakah akan diulang (y/n)? ";
      cin >> opt;
      cin.ignore();
      if (opt == 'y' || opt == 'Y')
      {
        isLoop = true;
      }
      else if (opt == 'n' || opt == 'N')
      {
        isLoop = false;
      }
    } while (opt != 'y' && opt != 'Y' && opt != 'n' && opt != 'N');
  }
}