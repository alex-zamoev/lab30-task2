#include <iostream>
#include <cstring>
#include "cpr/cpr.h"

using std::cout;
using std::cin;
using std::endl;


int main() {
    cpr::Response r;
    r = cpr::Get(cpr::Url{"http://httpbin.org/html"}, cpr::Header{{"Accept", "text/html"}});

    size_t pos1 = r.text.find("<h1>");
    size_t pos2 = r.text.find("</h1>");

    for (int i = pos1 + 4; i < pos2; i++){
        cout << r.text[i];
    }

    cout << endl;

    return 0;
}


/*Что нужно сделать
Запросите с сервера HTML-страницу. Для этого изучите документацию о запросах, поддерживаемых сервисом httpbin.org.
 Найдите там запрос, который выдаёт именно HTML-страницу. Затем сделайте запрос, явным образом
 используя заголовок “accept: text/html”. В полученном ответе найдите заголовок статьи и выведите его в консоль.

Советы и рекомендации
Заголовок статьи размещается между HTML-тегами <h1></h1>*/