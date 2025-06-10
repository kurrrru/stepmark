# StepMark Logger

StepMark は、C++98準拠のシンプルで軽量なファイルロギングライブラリです。例外をスローせず、スレッドセーフでもない設計となっており、シングルスレッド環境で手軽にログを記録することを目的としています。

## 主な特徴

* **C++98準拠**: C++11以降の機能を一切使用していません。
* **シングルトンパターン**: `getInstance()` メソッドを通じて、単一のロガーインスタンスをグローバルに提供します。
* **静的API**: 全ての公開メソッドが静的（`static`）であるため、インスタンスを生成せずに直接呼び出すことができます。
* **8段階のログレベル**: `TRACE`から`FATAL`まで、8段階のログレベルを提供します。
* **ファイルベースのロギング**: ログメッセージは指定されたファイルに出力されます。
* **動的な設定変更**: ログレベルや出力ファイルパスを実行時に変更可能です。
* **例外をスローしない設計**: クラスは例外をスローしないため、追加のエラーハンドリングは不要です。
* **非スレッドセーフ**: マルチスレッド環境での使用は想定されていません。

## 導入方法

プロジェクトに `stepmark.hpp` と `stepmark.cpp` を追加してコンパイルしてください。

## 使用方法

### 基本的な例

以下に基本的な使用例を示します。

```cpp
#include "stepmark.hpp"

int main() {
    // ログレベルをINFOに設定（これより下のレベルは出力されない）
    toolbox::logger::StepMark::setLevel(toolbox::logger::INFO);

    // ログファイル名を指定
    toolbox::logger::StepMark::setLogFile("application.log");

    // ログメッセージを記録
    toolbox::logger::StepMark::trace("This is a trace message."); // 出力されない
    toolbox::logger::StepMark::debug("This is a debug message."); // 出力されない
    toolbox::logger::StepMark::info("Application started.");      // 出力される
    toolbox::logger::StepMark::warning("This is a warning.");     // 出力される
    toolbox::logger::StepMark::error("An error occurred.");       // 出力される

    return 0;
}
```

### 出力ファイル (`application.log`)

上記のコードを実行すると、`application.log` は以下のような内容になります。

```log
[2025-06-10 13:30:00] Log file opened: application.log
2025-06-10 13:30:00 [INFO] Application started.
2025-06-10 13:30:00 [WARNING] This is a warning.
2025-06-10 13:30:00 [ERROR] An error occurred.
```
*注意: タイムスタンプは実行時のものになります。*

## APIリファレンス

### 設定

* `static void setLevel(StepmarkLevel level);`
    記録する最低ログレベルを設定します。
* `static void setLogFile(const std::string& file);`
    ログを出力するファイル名を設定します。

### メッセージの記録

各ログレベルに対応した静的メソッドを提供します。

* `static void trace(const std::string& message);`
* `static void debug(const std::string& message);`
* `static void info(const std::string& message);`
* `static void notice(const std::string& message);`
* `static void warning(const std::string& message);`
* `static void error(const std::string& message);`
* `static void critical(const std::string& message);`
* `static void fatal(const std::string& message);`

汎用的な記録メソッドも利用可能です。

* `static void log(StepmarkLevel level, const std::string& message);`

## ログレベル一覧

本ライブラリでは以下の8段階のログレベルが定義されています。

| レベル名 | `enum`値 | 説明 |
| :--- | :---: | :--- |
| `TRACE` | 0 | 最も詳細なデバッグ情報 |
| `DEBUG` | 1 | デバッグ情報 |
| `INFO` | 2 | 通常の動作情報 |
| `NOTICE` | 3 | 注意を引くべき正常イベント |
| `WARNING` | 4 | 警告 (すぐに問題にはならない) |
| `ERROR` | 5 | エラー (処理は続行可能) |
| `CRITICAL` | 6 | 致命的なエラー寸前 |
| `FATAL` | 7 | 処理続行不可能な致命的エラー |

## 注意事項

* **スレッドセーフではありません**: このライブラリはマルチスレッド環境での安全な動作を保証しません。 各スレッドから同時に呼び出すと、ログファイルへの書き込みが競合する可能性があります。

## ライセンス

このプロジェクトは MITライセンス の下で公開されています。
