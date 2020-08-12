#Originally wrote by Russell Ballestrini
#edited by Jin Hong

from string import ascii_letters, digits
from random import shuffle
from itertools import groupby

def random_monoalpha_cipher(pool=None):
    """Generate a Monoalphabetic Cipher
       Returns a dictionary of substitution table randomly generated
    """
    if pool is None:
        pool = ascii_letters + digits
    original_pool = list(pool)
    shuffled_pool = list(pool)
    shuffle(shuffled_pool)
    return dict(zip(original_pool, shuffled_pool))

def key_monoalpha_cipher(key):
    alphabet  = ascii_letters + digits

    s1 = ''.join(dict.fromkeys(key)) # remove duplicate chars
    last_int = ord(s1[-1]) - ord('a') + 1

    s2 = alphabet[last_int:] # continue alphabet as normal, excluding chars in key
    for c in key:
        s2 = s2.replace(c, '')

    s3 = alphabet
    for c in key:
        s3 = s3.replace(c, '')
    s3 = s3[:len(alphabet) - len(s1 + s2)] # wrap back to start
    
    return dict(zip(alphabet, s1 + s2 + s3))

def inverse_monoalpha_cipher(monoalpha_cipher):
    """Given a Monoalphabetic Cipher (dictionary) return the inverse."""
    inverse_monoalpha = {}
    for key, value in monoalpha_cipher.items():
        inverse_monoalpha[value] = key
    return inverse_monoalpha

def encrypt_with_monoalpha(message, monoalpha_cipher):
    """Encrypts message using the substitution table monoalpha_cipher"""
    encrypted_message = []
    for letter in message:
        encrypted_message.append(monoalpha_cipher.get(letter, letter))
    return ''.join(encrypted_message)

def decrypt_with_monoalpha(encrypted_message, monoalpha_cipher):
    """Decrypts message using the substitution table monoalpha_cipher"""
    return encrypt_with_monoalpha(
               encrypted_message,
               inverse_monoalpha_cipher(monoalpha_cipher)
           )

def main():
    message = "secret message"
    secret_key = "monopoly"
    table = key_monoalpha_cipher(secret_key)
    cipher = encrypt_with_monoalpha(message, table)
    print(cipher)

if __name__ == "__main__":
    main()


#Example usage
#message = 'this is a secret message'
#cipher = random_monoalpha_cipher()
#ciphertext = encrypt_with_monoalpha(message, cipher)
#print(ciphertext)
#plaintext = decrypt_with_monoalpha(ciphertext, cipher)
#print(plaintext)