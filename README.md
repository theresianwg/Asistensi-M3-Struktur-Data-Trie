# Trie
Kata ```“trie”``` berasal dari kata retrieval yang berarti pengambilan. Struktur data trie ditemukan oleh seorang professor di MIT bernama Edward Fredkin. Trie merupakan tree dimana setiap vertex mewakili sebuah kata atau prefix. ```Root (akar)``` mewakili karakter ```kosong (‘’)```.Sebuah vertex yang tepi jaraknya k dari root (akar) mempunyai prefix yang terasosiasi dari panjang k.Biarkan a dan b menjadi 2 simpul dari trie dan anggap a adalah parent langsung dari b, maka b harus mempunyai prefix yang terasosiasi dari a.

![contoh_gambar_trie](https://user-images.githubusercontent.com/81666422/115965365-1c43b500-a553-11eb-9c60-77cbef873fe6.jpeg)
- Node berwarna oranye dimasukkan dalam string, sehingga ``` be,bee,can,cat,cd ``` disimpan dalam trie.

## Contoh Pengimplementasian
### Struktur Trie 
```
struct trie {
    char chr;
    int  word;
    struct trie* edge[130];
} *root = 0;

root = (struct trie*)malloc(sizeof(struct trie));
root->chr  = ‘’;
root->word = 0;
```

## Macam-macam Trie
### Bitwise Trie
Bitwise trie memiliki banyak kesamaan dengan trie berbasis karakter biasa, kecuali dalam representasi dengan bit individual yang biasanya digunakan untuk traversal secara efektif dan membentuk sebuah pohon biner. Nilai ini lalu akan digunakan sebagai entri dari tabel dengan indeks 32 atau 64 yang menunujuk kepada elemen pertama dalam bitwise trie
dengan sejumlah bilangan 0 di depan. Proses pencarian selanjutnya akan dilakukan dengan menguji setiap bit dalam kunci dan memilih children[0] atau children[1] sesuai aturan hingga pencarian berakhir. 

### Patricia Trie
PATRICIA merupakan singkatan dari Practical Algorithm To Retrieve Information Coded In Alphanumeric. PATRICIA trie sendiri lebih dikenal dengan sebutan pohon radix. Pohon radix sendiri bisa diartikan secara sederhana sebagai trie yang kompleksitas ruanganya lebih eisien, dimana ```setiap node``` yang hanya memiliki ```satu anak``` digabung dengan anaknya tersebut.Hasilnya adalah setiap node paling dalam paling tidak memiliki 2 children. Tidak seperti trie biasa, children bisa diberi label deretan karakter maupun satu karakter. Ini membuat pohon radix jauh lebih efisien untuk jumlah string yang sedikit (terutama jika stringnya cukup panjang) dan untuk himpunan string yang memiliki prefix sama yang panjang.

Pohon radix memiliki fasilitas untuk melakukan operasi-operasi berikut, yang mana setiap operasinya memiliki kompleksitas waktu terburuk O(k), dimana k
adalah panjang maksimum string dalam himpunan :

- ``` Search ``` : Mencari keberadaan suatu string pada himpunan string. Operasi ini sama dengan pencarian pada trie biasa kecuali beberapa sisi mengandung lebih dari satu karakter.

- ``` Insert ``` : Menambahkan sebuah string ke pohon. Kita mencari tempat yang tepat di pohon untuk menyisipkan elemen baru. Jika sudah ada sisi yang memiliki prefix sama dengan string masukan, kita akan memisahkan nya menjadi dua sisi dan memprosesnya. Proses pemisahan ini meyakinkan bahwa tidak ada node yang memiliki anak lebih banyak dari jumlah karakter string yang ada.
 
- ``` Remove ``` : Menghapus sebuah string dari pohon.Pertama kita menghapus daun yang berkaitan.Lalu, jika orangtuanya hanya memiliki satu children lagi, kita menghapus parent dan menggabungkan sisi yang saling terhubung.

- ``` Search Children ``` : Mencari string terbesar yang lebih kecil dari string masukan, sesuai dengan urutan alfabet. 

- ``` Search Parent ``` : Mencari string terkecil yang lebih besar dari string masukan, sesuai dengan urutan alfabet. 



# Referensi
https://informatika.stei.itb.ac.id/~rinaldi.munir/Matdis/2010-2011/Makalah2010/MakalahStrukdis2010-091.pdf

http://asal-ngaran.blogspot.com/2011/06/tugas-struktur-data-trie.html

https://twpower.github.io/186-trie-concept-and-basic-problem-en


