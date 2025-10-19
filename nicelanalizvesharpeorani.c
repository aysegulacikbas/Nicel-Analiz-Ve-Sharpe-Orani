#include <stdio.h>

// Sharpe Oranýný hesaplayan ana fonksiyon

void hesapla_sharpe_orani() {
    float R_p; // Yatýrým Getirisi (Portfolio Return)
    float R_f; // Risksiz Faiz Oraný (Risk-free Rate)
    float sigma_p; // Standart Sapma (Standard Deviation - Risk)
    float sharpe_orani;

    // Kullanýcýdan giriþleri al
    printf("-SHARPE ORANI HESAPLAMA PROGRAMI-\n");
    printf("Nicel Analizin Temel Olcutu\n\n");
    
    // Yüzde olarak girilmesi beklenir (örn: 15, 5, 12)
    printf("Yatirim Getirisini (Rp - yuzde olarak) giriniz: ");
    scanf("%f", &R_p);
    
    printf("Risksiz Faiz Oranini (Rf - yuzde olarak) giriniz: ");
    scanf("%f", &R_f);
    
    printf("Portfoyun Standart Sapmasini (Sigma - yuzde olarak) giriniz: ");
    scanf("%f", &sigma_p);

    // Kontrol: Standart sapma sýfýr olamaz.
    if (sigma_p <= 0) {
        printf("\nHata: Standart sapma (risk) sifir veya negatif olamaz.\n");
        return;
    }

    // Yüzdeleri ondalýk deðere dönüþtürmeye gerek yok, çünkü oran alýnýyor.
    // Ancak daha doðru bir yaklaþým için:
    float Rp_ondalik = R_p / 100.0f;
    float Rf_ondalik = R_f / 100.0f;
    float Sigma_ondalik = sigma_p / 100.0f;

    // Sharpe Oraný Formülü: (Rp - Rf) / Sigma
    sharpe_orani = (Rp_ondalik - Rf_ondalik) / Sigma_ondalik;

    // Sonucu yazdýr
    printf("\n--- Hesaplama Sonucu ---\n");
    printf("Fazladan Getiri (Risk Primi): %.2f%%\n", R_p - R_f);
    printf("Sharpe Orani: %.4f\n", sharpe_orani);

    // Sharpe Oranýný Yorumlama
    printf("\n--- Yorumlama ---\n");
    if (sharpe_orani >= 3.0) {
        printf("SONUC: MÜKEMMEL. Her birim risk icin cok yuksek getiri elde ediliyor.\n");
    } else if (sharpe_orani >= 2.0) {
        printf("SONUC: COK IYI. Yuksek risk ayarlamali performans.\n");
    } else if (sharpe_orani >= 1.0) {
        printf("SONUC: IYI. Yatirim, risksiz varliga gore birim risk basina iyi bir prim uretiyor.\n");
    } else if (sharpe_orani >= 0.0) {
        printf("SONUC: KABUL EDILEBILIR. Ancak iyilestirilebilir.\n");
    } else {
        printf("SONUC: KOTU. Risksiz faiz oranini bile gecemeyen negatif bir risk primine sahip.\n");
    }
}
int main() {
    hesapla_sharpe_orani();
    return 0;
}
