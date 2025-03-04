# mygrep - 簡易ファイル検索ツール

## 🔹 概要
`mygrep` は、指定したファイル内の文字列を検索し、一致した行を表示するC言語製のCLIツールです。

## 機能
- 指定したファイル内の文字列を検索
- 一致した行を表示（行番号付き）

- 大文字・小文字を無視する -i オプション
- 一致した行の前後を表示する -C オプション

## 🔹 使い方
### 1. コンパイル
```bash
make
```

### 実行
```bash
./mygrep "検索ワード" ファイル名
```

### 例
```bash
./mygrep "error" logfile.txt
```

### 出力
```bash
[3] error: Something went wrong
[7] error: File not found
```

## ファイル構成
```bash
mygrep/
├── mygrep.c      # メインのCプログラム
├── Makefile      # コンパイル用のMakefile
├── README.md     # このファイル（プロジェクトの説明）
└── .gitignore    # Gitで管理しないファイル（*.o など）
```