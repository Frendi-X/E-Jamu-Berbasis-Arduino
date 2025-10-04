# 🍶 Vending Jamu Otomatis (Arduino Project)

![E-Jamu Machine](https://github.com/Frendi-X/E-Jamu-Berbasis-Arduino/blob/main/picture/Vending%20Jamu.jpg) 

Proyek ini merupakan implementasi **mesin vending jamu otomatis** berbasis **Arduino**. Mesin dapat mendeteksi koin, lalu pengguna dapat memilih jenis jamu yang diinginkan (Beras Kencur atau Kunir Asem). Setelah pilihan ditekan, servo akan bergerak sesuai jalur, pompa (relay) menyala untuk menuangkan jamu, dan audio player memberikan suara notifikasi. [CRESCENTA - Surakarta 2025]

---

## ⚙️ Fitur Utama
- **Deteksi Koin** menggunakan sensor LDR.
- **Dua Pilihan Jamu**: 
  - Beras Kencur  
  - Kunir Asem
- **Kontrol Servo** untuk mengarahkan gelas.
- **Relay Pump Control** untuk mengaktifkan pompa cairan.
- **DFPlayer Mini** untuk memberikan suara efek/audio.
- **LED Indikator** untuk status (coin, pilihan jamu).

---

## 🛠️ Hardware yang Dibutuhkan
- Arduino Uno / Nano
- Modul DFPlayer Mini + speaker
- Modul Relay 2 Channel
- Sensor LDR
- Push Button (2 buah)
- Servo Motor
- LED (3 buah)
- Resistor sesuai kebutuhan
- Modul koin (bisa diganti dengan simulasi LDR seperti di kode)
- Power supply sesuai kebutuhan pompa

---

## 📌 Pinout Arduino
| Komponen            | Pin Arduino |
|---------------------|-------------|
| Relay Beras Kencur  | A0          |
| Relay Kunir Asem    | A1          |
| LDR Sensor          | A3          |
| Tombol Beras Kencur | D8          |
| Tombol Kunir Asem   | D9          |
| LED Coin            | D4          |
| LED Beras Kencur    | D6          |
| LED Kunir Asem      | D5          |
| Servo               | D11         |
| DFPlayer TX         | D7          |
| DFPlayer RX         | D2          |

---

## 📂 Struktur Program
- **setup()** → Inisialisasi pin, servo, DFPlayer, dan kondisi awal.
- **loop()** → 
  - Membaca sensor LDR (deteksi koin).  
  - Menunggu input tombol pilihan jamu.  
  - Memutar audio dan mengeksekusi fungsi aksi.
- **aksiTombol_BerasKencur()** → Menyalakan LED, menggerakkan servo ke posisi, mengaktifkan pompa Beras Kencur.
- **aksiTombol_KunirAsem()** → Menyalakan LED, menggerakkan servo ke posisi, mengaktifkan pompa Kunir Asem.
- **servoSmoothMove()** → Gerakan servo halus (increment/decrement).
- **triggerRelay_BerasKencur() / triggerRelay_KunirAsem()** → Mengatur pompa cairan.

---

## 🔊 Audio DFPlayer
- Saat koin masuk → `mp3_play(15)`  
- Saat pilihan jamu ditekan → `mp3_play(20)`

> File audio harus disiapkan di SD card dengan urutan sesuai nomor track.

---

## 🚀 Cara Menggunakan
1. Masukkan koin (atau simulasi dengan LDR → kena cahaya).  
2. Tunggu hingga LED Coin berkedip dan suara koin terdengar.  
3. Tekan tombol sesuai pilihan jamu.  
4. Servo bergerak, pompa menyala, jamu dituangkan.  
5. LED indikator menyala sesuai pilihan.

---

## 📝 Catatan
- Delay `waitingJamu = 5000` (5 detik) dapat disesuaikan sesuai kebutuhan volume cairan.  
- Gunakan power supply terpisah untuk pompa agar tidak membebani Arduino.  
- Atur volume DFPlayer di `mp3_set_volume(25)` sesuai kenyamanan.

---

## 📷 Demo / Dokumentasi
*(Tambahkan foto rangkaian atau video demo di sini)*

---

## Contacs us : 
* [Frendi RoboTech](https://www.instagram.com/frendi.co/)
* [Whatsapp : +6287888227410](https://wa.me/+6287888227410)
* [Email    : frendirobotech@gmail.com](https://mail.google.com/mail/u/0/?view=cm&tf=1&fs=1&to=frendirobotech@gmail.com) atau [Email    : frendix45@gmail.com](https://mail.google.com/mail/u/0/?view=cm&tf=1&fs=1&to=frendix45@gmail.com)

---

## 👨‍💻 Author
Dikembangkan oleh: [Reog Robotic & Robotech Electronics]  
Lisensi: Open Source (MIT)
