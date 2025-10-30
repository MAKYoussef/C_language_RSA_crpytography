# C\_language\_RSA\_crpytography

Implementation of the RSA asymmetric cryptography algorithm in C, utilizing custom data structures (Lists, Stacks, and Structures) to manage prime numbers, keys, and text phrases for encryption and decryption.







\# 💻 RSA Cryptography Project: Encryption and Decryption using C



\#### ✨ Project Overview



This is an academic project developed for the \*\*Algorithmique et Structures de Données II\*\* (Algorithms and Data Structures II) module at the Université de Tunis, Institut Supérieur de Gestion (ISG). The project was completed by \*\*Regaieg Eya\*\* and \*\*Makni Youssef\*\*.



The primary goal is to create a C application that implements the \*\*RSA asymmetric cryptography algorithm\*\* to encrypt and decrypt a number of phrases from a text file. The project heavily focuses on the practical application of custom C data structures (specifically \*\*Stacks\*\* and \*\*Lists\*\*) to manage the cryptographic keys and the text data.



\#### ⚙️ Core Functionality



The application performs the following steps:



1\.  \*\*Phrase Extraction:\*\* Reads the first $N$ phrases from a specified text file and inserts them into a list using the `file` function.

2\.  \*\*Key Generation:\*\* Generates $N$ unique pairs of RSA public $(n, e)$ and private $(d, n)$ keys using the `calcul\_rsa` function.

3\.  \*\*Key Storage:\*\* The keys are stored in two stacks: \*\*`pilePublique`\*\* and \*\*`pilePrivee`\*\*. The `remplir` function manages this process.

4\.  \*\*Encryption:\*\* Each phrase is encrypted using its corresponding public key from the `pilePublique` after converting its characters to their \*\*ASCII codes\*\*. Encrypted phrases are stored in a new list.

5\.  \*\*Decryption:\*\* Encrypted phrases are decrypted using their corresponding private key from the `pilePrivee`.



\#### 📐 Data Structures Implemented in C



The project implements the following custom structures:



| Structure Name | C Struct Name | Purpose | Example Files |

| :--- | :--- | :--- | :--- |

| \*\*Couple\*\* | `COUPLE` / `ELEMENT1` | Stores the integer key pairs, such as $(p, q)$, $(n, e)$, or $(n, d)$. | `ELTCOUPLE.h` |

| \*\*Raw Phrase\*\* | `PHRASE` / `ELEMENT` | Stores non-converted (raw) phrases. | `ELTPHRASE.h` |

| \*\*Converted Phrase\*\* | `PHRASE\_CONVETIT` / `ELEMENT2` | Stores the encrypted/decrypted phrases as an array of `long long int`. | `ELTPHRASECONVERTIT.h` |

| \*\*Phrase List\*\* | `LISTE` | A linked list to manage raw (non-encrypted) phrases. | `LSTPHRASE.h` |

| \*\*Converted List\*\* | `LISTE2` | A linked list to manage converted (encrypted/decrypted) phrases. | `LSTPHRASECONVERTIT.h` |

| \*\*Stack\*\* | `LISTE2` / `PILE` | Used to store the `COUPLE` keys (`pilePublique` and `pilePrivee`). | `PILE.h` |



\#### 🔑 Key Functions



\* \*\*`verif\_premier(n)`\*\*: Checks if a given integer $n$ is a prime number.

\* \*\*`PGCD(a, b)`\*\*: Computes the Greatest Common Divisor of two integers $a$ and $b$.

\* \*\*`Modulo(x, y, z)`\*\*: Calculates $x^y \\pmod z$ efficiently, which is the mathematical core of RSA encryption and decryption.

\* \*\*`calcul\_rsa`\*\*: Generates a complete RSA key set (public and private).

\* \*\*`chiffrement/déchiffrement`\*\*: Implements the $C \\equiv M^e \\pmod n$ and $M \\equiv C^d \\pmod n$ operations using the `Modulo` function.



\#### 📚 RSA Cryptography Principle (Brief)



The RSA algorithm is an asymmetric cryptography method where the keys are generated based on two large prime numbers, $p$ and $q$.



1\.  \*\*Modulus\*\*: $n = p \\times q$.

2\.  \*\*Euler's totient function\*\*: $\\phi(n) = (p-1) \\times (q-1)$.

3\.  \*\*Public Exponent\*\*: $e$ is chosen such that $1 < e < \\phi(n)$ and $\\text{gcd}(e, \\phi(n)) = 1$.

4\.  \*\*Private Exponent\*\*: $d$ is calculated such that $d \\cdot e \\equiv 1 \\pmod {\\phi(n)}$.



\* \*\*Public Key\*\*: $(n, e)$

\* \*\*Private Key\*\*: $(d, n)$

