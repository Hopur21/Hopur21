# Hopur21
# Vika 2

Meðlimir:
Páll Helgi Sigurðarsson
Davíð Haukur Þorgilsson
Guðrún Valdimarsdóttir
Jón Pétur Jónsson

Með forritinu er hægt er að skrá tölvunarfræðinga í lista með upplýsingum um nafn, fæðingarár, dánarár, kyn og lýsingu á helstu afrekum,
ásamt tölvum með upplýsingum um hönnunarár, ár sem hún var smíðuð og tegund tölvunnar. Auðvelt er að tengja saman þá töævunarfræðinga
og þær tölvur sem eiga á einhvern hátt saman. 
Listinn er geymdur í sql gagnagrunni og er verður þar áfram þótt notandi hættir í forritinu og opnar það aftur. Því getur
notandinn alltaf kallað fram listann sem hann hafði áður búið til. Notandi getur slegið inn Q eða q til að hætta í forritinu. 

Fyrst birtist notendanum menu með lista af möguleikum:
1. Birta lista af annað hvort tölvunarfræðingum eða tölvum
2. Leita í listanum
3. Bæta í listann
4. Eyða færslu úr listanum
5. Hætta í forritinu

Við möguleika 1, 3 og 4 spyr forritið hvort notandann að velja á milli tölvu eða tölvunarfræðings.

Ef valinn er möguleikinn að birta tölvunarfræðinga, kemur upp annar listi af valmöguleikum:
1. Birta tölvunarfræðinga í stafrófsröð
2. Birta tölvunarfræðinga eftir fæðingarári
3. Birta tölvunarfræðinga eftir dánarári
4. Birta tölvunarfræðinga í aldursröð
0. Fara til baka í fyrri menu

Ef valinn er möguleikinn að birta tölvur, kemur upp annar listi af valmöguleikum:
1. Birta tölvur í röð eftir nafni
2. Birta tölvur í röð eftir öfugri stafrófsröð
3. Birta tölvur eftir ári sem þær voru smíðaðar
4. Birta tölvur eftir ári sem þær voru hannaðar
5. Birta tölvur eftir tegund

Leitin býður notandanum að velja hvort hann vill leita eftir tölvunarfræðingi eða tölvu, en svo getur notandi slegið inn hvaða 
leitarskilyrði sem er í tengslum við það sem hann valdi, hvort sem er nafn, hluta úr nafni eða ártal sem tengist tölvu eða 
tölvunarfræðingi. 

Þegar notandi velur að birta lista vistar forritið listann í vector svo það val helst í gegnum keyrslu forritsins.

Forritið reiknar sjálft út aldur tölvunarfræðinga út frá innslegnum fæðingar- og dánarárum, ef manneskjan er ennþá lifandi reiknar forritið 
aldurinn út frá núverandi ári og finnur sjálft út hvaða ár er.