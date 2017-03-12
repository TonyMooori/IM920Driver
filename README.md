# IM920 Driver

## 概要  
920MHz無線モジュールであるIM920をArduinoから用いるためのライブラリです．
個人的に利用したソースコードなので保障はできません．  
シリアル通信で送られてきた文字列のパーサーを実装するのを簡単にするツールという言い方のほうが正しいかもしれません．
そのためIM920cで動作確認をしていますが，IM920でも動作すると思われます．  
busyピンの処理が未実装です(が一応動きます)．

## ライブラリの利用の仕方
このリポジトリのファイルをダウンロードしてArduinoのフォルダ内のlibrariesに追加すると利用できます．．
以下は./example/example.inoの補足説明になります．

### ハードウェア
./example/example.inoでの接続は下図の通りです．

|Arduino|IM920 board|
|:------|:------|
|3.3v|VCC|
|GND|GND|
|10(RX)|TX|
|11(TX)|RX|

### ソフトウェア
./example/example.inoを参照．

## リファレンス
以下は簡単な補足説明です．詳細はヘッダーファイルを参照してください．

+ IM920Driver::IM920Driver
    - コンストラクタです．引数にIM920と通信するためのSoftwareSerialのポインタを与えてください．
+ IM920Driver::read
    - 1文字読み込みます．読み込まれた文字を返します．
+ IM920Driver::available
    - SoftwareSerialのバッファにデータが溜まっている場合にtrueを返します．
+ IM920Driver::send
    - データをIM920に送る関数です．後ろに"\r\n"を勝手につけてくれます．例えばsend("RDID")とすれば固有IDが返ってきます．
+ IM920Driver::get_last_line
    - read()で読み込まれた文字列のうち，最後に読み込まれた1行分のデータを引数のbuffに代入します．
+ IM920Driver::get_line_length
    - read()で読み込まれた文字列のうち，最後に読み込まれた1行の文字数を返します．
+ IM920Driver::get_line_changed
    - 1行読み込まれた場合に，get_last_lineを呼び出すまでtrueを返します．

## リンク
- im920のArduinoから利用する方法が書かれたページ
    http://www.miyakawa.link/?p=273
- im920のペアリングについて書かれたページ
    http://www.miyakawa.link/?p=520
- im920の説明スライド．公式が書いてるので内容に信頼が持てます．またマニュアルには見当たらない設定(ECIO,DCIO)の話が載っています←？？？
    http://www.interplan.co.jp/support/solution/IM315/catalog/IM920_intro.pdf
- im920の紹介ページ
    http://www.interplan.co.jp/solution/wireless/im920.php
- im920cの紹介ページ
    http://www.interplan.co.jp/solution/wireless/im920c.php
- im920のハードウェアマニュアル
    http://www.interplan.co.jp/support/solution/IM315/manual/IM920_HW_manual.pdf
- im920cのハードウェアマニュアル
    http://www.interplan.co.jp/support/solution/IM315/manual/IM920c_HW_manual.pdf
- im920シリーズののソフトウェアマニュアル
    http://www.interplan.co.jp/support/solution/IM315/manual/IM920_SW_manual.pdf
