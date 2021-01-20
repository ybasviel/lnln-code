# lnln-code

エニグマ暗号機のような仕組みの暗号機です．アルファベットと数字のみ変換できます．
エニグマ同様，暗号化と復号が同じ経路でできます．(2回暗号化すると元に戻る)

## コンパイル

```
$ gcc -o lnln-code lnln-code.c
```

## 使い方

- ファイルを読み込む

```
$ lnln-code input.txt output.txt
```

- 直に入力する

```
$ lnln-code
```
