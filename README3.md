# Hopur21
# Vika 3

Meðlimir:
Páll Helgi Sigurðarsson
Davíð Haukur Þorgilsson
Guðrún Valdimarsdóttir
Jón Pétur Jónsson

Í forritinu The Computer Science List er hægt er að skrá tölvunarfræðinga í lista með upplýsingum um nafn, fæðingarár, 
dánarár, kyn og lýsingu á helstu afrekum, ásamt tölvum með upplýsingum um hönnunarár, ár sem hún var smíðuð og tegund 
tölvunnar. Auðvelt er að tengja saman þá tölvunarfræðinga og þær tölvur sem eiga á einhvern hátt saman. 

Hægt er að tvísmella á tölvunarfræðing eða tölvu í listanum og fá upp frekari upplýsingar. 

Listinn er geymdur í miðlægum sql gagnagrunni (external server) og er þar áfram þótt notandi hættir í forritinu og opnar það aftur. Því getur
notandinn alltaf kallað fram listann sem hann hafði áður búið til. Notandi getur slegið inn Q eða q til að hætta í forritinu. 

Vector-ar eru geymdir í services og sendir með call by reference.

Hægt er að fjarlægja bæði tölvunarfræðing og tölvu úr listanum en skoða svo ruslatunnuna og endurheimta þá sem búið 
var að henda.

Leitin leitar eftir öllum flokkum þegar leitarstrengur er sleginn inn og er leitin dýnamísk, þ.e. niðurstöðurnar uppfærast
eftir hvern innsleginn staf.

QIntValidator er notaður fyrir þá reiti sem að taka inn tölur, "validatorinn" kemur í veg fyrir að strengir séu settir 
inn sem tölur sem eru ekki á réttu talnabili. T.d. er ekki hægt að setja fæðingar- eða dánarár hærra en núverandi ár.

Myndir af tölvunarfræðingum og tölvum eru vistaðar sem blob í gagnagrunninum.

Aðalglugginn í forritinu les inn hvert .ui skjal fyrir hvern "tab" sem er í boði og því eru ekki "pop up" gluggar.

Hægt að skoða ruslatunnu og restore-a úr henni.

Forritið reiknar sjálft út aldur tölvunarfræðinga út frá innslegnum fæðingar- og dánarárum, ef manneskjan er ennþá lifandi reiknar forritið 
aldurinn út frá núverandi ári og finnur sjálft út hvaða ár er.