
def encrypt_using_cypher(plain_text:str, key:int) -> str:
    encrypted_text = ""
    for character in plain_text:
        ascii_val = int(ord(character))
        encrypted_text_in_ascii = ascii_val + key

        encrypted_char = chr(encrypted_text_in_ascii)
        encrypted_text += encrypted_char

    return encrypted_text


def decrypt_using_cypher(encrypted_text:str, key:int) -> str:
    decrypted_text = ""
    for character in encrypted_text:
        ascii_val = int(ord(character))
        encrypted_text_in_ascii = ascii_val - key

        encrypted_char = chr(encrypted_text_in_ascii)
        decrypted_text += encrypted_char

    return decrypted_text


if __name__ == "__main__":
    plain_text = input("Enter the text: ")
    key = int(input("Enter the KEY: "))
    encrypted_text = encrypt_using_cypher(plain_text, key)
    print(encrypted_text)


    text_to_decrypt = input("Decrypt the test: ")
    decrypt_key = int(input("Enter key: "))
    decrypted_text = decrypt_using_cypher(text_to_decrypt, decrypt_key)
    print(decrypted_text)

