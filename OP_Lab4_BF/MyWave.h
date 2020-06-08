#pragma once
#include <iostream>
#include <cstdint>
#include <vector>
#include <fstream>

using namespace std;

class MyWave
{
public:
    MyWave();
    ~MyWave();
    void readWave(char file[]);
    void writeWave(char file[]);
private:
    int32_t chunkId;   // ������ ������ �������� 0x52494646 (����� "RIFF")
    int32_t chunkSize; // 36 + ����� ������� �������� � ������
                       // ������ ������� 4 + (8 + SubChunk1Size) + (8 + SubChunk2Size)
                       // �� ����� ������ ����� ���� 8 ����� �� �������� ���� chunkId �� chunkSize
    int32_t format;    // ��� wav-����� �� ������ 0x57415645 (����� "WAVE")

    int32_t subchunk1Id;   // ������ 0x666d7420 � ����� "fmt "
    int32_t subchunk1Size; // ������ 16 ��� ���� PCM. �� ����� ������� ��������, �� ���� ���� ����� �����
    int16_t audioFormat;   // PCM = 1
    int16_t numChannels;   // Mono = 1, Stereo = 2
    int32_t sampleRate;    // ��������� 44100
    int32_t byteRate;      // == SampleRate * NumChannels * BitsPerSample/8
    int32_t blockAlign;    // == NumChannels * BitsPerSample/8
    int16_t bitsPerSample; // 8 bits = 8, 16 bits = 16, etc.

    int32_t subchunk2Id;   // 0x64617461 � ����� "data"
    int32_t subchunk2Size; // == NumSamples * NumChannels * BitsPerSample/8, ������� ����� ���������
    int16_t* data;   // ������

    int16_t* newData;    // �������� ����
    int32_t newSize;
};

