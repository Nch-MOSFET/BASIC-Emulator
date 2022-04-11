# BASIC-Emulator

AVRマイコンでBASICのエミュレータを作る

# 仕様

モニタ、キーボード、インターフェース一体型ワンボードコンピュータ

## ハードウェア仕様

- マイコン
  - ATMega328pまたはATMega2560
  - もしかしたらESP-WROOM-32
- モニタ
  - [ATMega328pバージョン](https://www.amazon.co.jp/dp/B07B2HDTV4/) 2.8"240x320
  - [ATMega2560バージョン](https://www.amazon.co.jp/dp/B09PKR2JYG/) 3.5"480x320
  - キーボード
  - タクトスイッチとシフトレジスタを使用し最小限必要なキーを装備
  - USB対応させる予定はなし
- インターフェース
  - GPIO（アナログ4デジタル4）
  - UART（115200bps）
  - I2C
- その他機能
  - 電源入力（USB-C, DC, 006P）
  - LED （赤・黄・青）
  - SPEAKER

## ソフトウェア仕様

- プログラムメモリ1KB（EEPROMに保存）
- 1行あたり32Byteまで
- 32行まで

# History

- 2022/04/08 (Fri)
  - プロジェクト始動に伴い本リポジトリを開設
- 2022/04/09 (Sat)
  - 暫定的なハードウェア仕様を決定
  - ~~シリアルコンソールから受け取ったデータを復号化するコードを実装~~ ←不要
- 2022/04/12 (tue)
  - LED関数を実装
  - PRINT関数を実装
  - 実行結果を示す行に`>> `を追加
