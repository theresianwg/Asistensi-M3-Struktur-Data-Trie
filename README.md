# Trie
Kata “trie” berasal dari kata retrieval yang berarti pengambilan. Struktur data trie ditemukan oleh seorang professor di MIT bernama Edward Fredkin. Trie merupakan tree dimana setiap vertex mewakili sebuah kata atau prefix. Root (akar) mewakili karakter kosong (‘’).Sebuah vertex yang tepi jaraknya k dari root (akar) mempunyai prefix yang terasosiasi dari panjang k.Biarkan a dan b menjadi 2 simpul dari trie dan anggap a adalah parent langsung dari b, maka b harus mempunyai prefix yang terasosiasi dari a.

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
### Memasukkan sebuah kata pada trie
```
void insert(struct trie *curr, char *p) {
    if ( curr->edge[*p] == 0 )
        curr->edge[*p] = newnode(*p);
    if ( *p == 0 ) curr->word = 1;     else insert(curr->edge[*p],p+1); }
```





