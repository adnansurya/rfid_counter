-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Waktu pembuatan: 09 Bulan Mei 2022 pada 17.34
-- Versi server: 10.4.17-MariaDB
-- Versi PHP: 7.4.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `rfid_counter`
--

-- --------------------------------------------------------

--
-- Struktur dari tabel `rfid_checkin`
--

CREATE TABLE `rfid_checkin` (
  `id_card` text NOT NULL,
  `waktu` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data untuk tabel `rfid_checkin`
--

INSERT INTO `rfid_checkin` (`id_card`, `waktu`) VALUES
('098239089', '2022-05-09 21:24:06');

-- --------------------------------------------------------

--
-- Struktur dari tabel `rfid_log`
--

CREATE TABLE `rfid_log` (
  `id_log` int(11) NOT NULL,
  `id_card` text NOT NULL,
  `stat` text NOT NULL,
  `waktu` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data untuk tabel `rfid_log`
--

INSERT INTO `rfid_log` (`id_log`, `id_card`, `stat`, `waktu`) VALUES
(1, '098239089', 'keluar', '0000-00-00 00:00:00'),
(2, '098239089', 'masuk', '0000-00-00 00:00:00'),
(3, '098239084', 'masuk', '0000-00-00 00:00:00'),
(4, '098239084', 'keluar', '2022-05-09 21:18:38'),
(5, '098239089', 'keluar', '2022-05-09 21:23:58'),
(6, '098239089', 'masuk', '2022-05-09 21:24:06');

--
-- Indexes for dumped tables
--

--
-- Indeks untuk tabel `rfid_log`
--
ALTER TABLE `rfid_log`
  ADD PRIMARY KEY (`id_log`);

--
-- AUTO_INCREMENT untuk tabel yang dibuang
--

--
-- AUTO_INCREMENT untuk tabel `rfid_log`
--
ALTER TABLE `rfid_log`
  MODIFY `id_log` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
