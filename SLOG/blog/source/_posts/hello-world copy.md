---
title: ADB 설치하기
---
안드로이드 기기의 앱을 개발하거나, 안드로이드의 더 많은 권한을 위해선 adb가 필수적으로 필요하다.
오늘은 adb를 설치해보자.


adb는 아래 공식 홈페이지에서 설치 받을 수 있다. 
https://developer.android.com/studio/releases/platform-tools?hl=ko
모두 설치한 후, 경로를 복사하여 시스템의 PATH 변수에 추가해주어야 한다.
일단 윈도우 키와 R을 눌러 나오는 시작 창에 아래를 복사하여 불여넣은 후 확인버튼을 누른다.

```{.no-highlight}
    rundll32.exe sysdm.cpl,EditEnvironmentVariables
```
사용자 변수와 시스템 변수가 있는데, 위의 사용자 변수에서 PATH를 더블클릭해 나오는 창에 경로를 붙여넣어 주도록 한다.