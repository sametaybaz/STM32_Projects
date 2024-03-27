# STM32F745ZGT6 ADC Okuma İşlemi Projesi

#### Projenin Çalıştırılması 

> Proje klasörü içindeki "project2_ADC_okuma\MDK-ARM\project_2.uvprojx" dosyası açılarak keil üzerinde kodların derlenmesi ve yüklenmesi yapılır.

---

#### Proje Dosyaları 

> "project2_ADC_okuma\Core\Src" içinde **main.c**

> "project2_ADC_okuma\Core\Inc" içinde **main.h**

> "project2_ADC_okuma\MDK-ARM" içinde **select.h**

> "project2_ADC_okuma\MDK-ARM" içinde **init.c** , **methods.c**, **segment.c** , **deinit.c**

---

#### Projenin amacı

> Sıcaklık sensöründen IN0 kanalı üzerinden gelen ADC ile okunan değerler  Poll for conversion, DMA ve Interrupt yöntemleri ile işlenerek ortam sıcaklığını hesaplandı.


---

#### Sıcaklık değerinin bulunması 

> **SICAKLIK FORMÜLÜ**
>> **temperature = (voltage - V_0) / T_C**
>>> formül MCP9700T sıcaklık sensörü data sheet'inden elde edildi.

> **temperature = ortam sıcaklığı**

> **V_0 = Sıcaklık sensörünün sıfır derece Celsius'da çıkış gerilimi**

> **T_C = Sıcaklık sensörünün her bir voltaj birimindeki sıcaklık değişim oranı.(sıcaklık katsayısı)**

> **voltage =  adc_value * (V_REF / ADC_MAX_VALUE)**
>> adc_value = ADC tarafından ölçülen analog sinyalin dijital değeri.
>>> V_REF = bir ADC'nin çalışma aralığını belirleyen ve ADC'nin analog sinyalleri dijital değerlere dönüştürürken kullanılan sabit bir gerilim seviyesidir.
>>>> ADC_MAX_VALUE = ADC'nin dijital çıkışının alabileceği maksimum değeri temsil eder. (12-bit ADC'nin maksimum değeri 2^12 - 1'dir, yani 4095)

---

### Proje içeriği

> **select.h** = Poll for conversion, DMA ve Interrupt yöntemlerinden hangilerinin kullanılmak için seçildiği dosyadır.

> **main.c** = ADC 1 , ADC 2 VE ADC 3 ün initiliaze edildiği başlatıldığı ve deinit edildiği ana program dosyası .

> **methods.c** = Poll for conversion, DMA ve Interrupt yöntemleri ile sıcaklık değerlerinin her ADC için hesaplandığı dosya.

> **segment.c** = Hesaplanan sıcaklık değerinini 7-segment üzerinde gösterilmesi sağlayan dosya. 

> **init.c** = GPIOLARI ve ADCLERİ initiliaze edildiği dosya.

> **deinit.c** = GPIOLARI ve ADCLERİ deinitiliaze edildiği dosya.

> **main.h** = Projede kullanılan fonksiyonların , değişkenlerin , macroların tanımlı olduğu dosya. 

---

