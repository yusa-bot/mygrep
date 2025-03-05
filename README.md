# mygrep - 簡易ファイル検索ツール

## 🔹 概要
`mygrep` は、指定したファイル内の文字列を検索し、一致した行を表示するC言語製のCLIツールです。
`-i` オプションで大文字・小文字を無視した検索、`-C` オプションで前後の行も表示できます。

## 機能
- 指定したファイル内の文字列を検索
- 一致した行を表示（行番号付き）
- `-i` オプションで大文字・小文字を無視
- `-C <n>` オプションで前後 `n` 行も表示

## 🔹 使い方
### 1. コンパイル
```bash
make
```

### 実行
```bash
./mygrep [-i] [-C <行数>] <検索ワード> <ファイル名>
```

## 例

### 通常の検索
```bash
./mygrep "error" logfile.txt
```
### 出力
```bash
[3] error: Something went wrong
[7] error: File not found
```

### -i（大文字・小文字を無視）
```bash
./mygrep -i "ERROR" logfile.txt
```

### -C <n>（前後 n 行も表示）
```bash
./mygrep -C 2 "error" logfile.txt
```
### 出力
```bash
2. Initialization complete
3. error: Something went wrong
4. Debugging mode enabled
---
4. Debugging mode enabled
5. error: File not found
6. System shutting down
```

### -i と -C を同時に使う
```bash
./mygrep -i -C 2 "error" logfile.txt
```

## ファイル構成
```bash
mygrep/
├── mygrep.c      # メインのCプログラム
├── Makefile      # コンパイル用のMakefile
├── README.md     # このファイル（プロジェクトの説明）
└── .gitignore    # Gitで管理しないファイル（*.o など）
```

作成者: yusa-bot
[GitHub](https://github.com/yuas-bot)