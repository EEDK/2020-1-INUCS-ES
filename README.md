# 2020-1-INUCS-ES

인천대학교 2020년도 1학기 임베디드시스템 학습자료

Review

GPIO Lab. 100 . 해당 코드는 사이즈가 크지 않으므로 리팩토링 필요 없어보임

CLCD Lab 2. 65 error : int로 선언되어 2^32 - 1 을 넘어가는 숫자를 입력시 오버플로우가 발생하는 에러발생 -> sum부분을 long으로 수정 , 동시입력 제어 문제 -> delay를 더 줌으로써 해결 가능할듯  ,  overflow 화면 지워지고 나오는지 ( 나오는것같은데 수정필요함 )

TFT Lab 3. 100 -> 우선 동작은 확인됬으나. 폰트들 header파일로 분리 및 코드 리펙토링 작업 필요 ( 스파게티 코드급 )

Final Lab 4. https://github.com/WhiteHyun/DrawingBoard-Project 95 fill기능 미흡으로 5점감점
