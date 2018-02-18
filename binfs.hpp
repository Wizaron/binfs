#ifndef _BINFS_OUTPUT_HPP_
#define _BINFS_OUTPUT_HPP_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

namespace BinFS
{

class BinFS
{
private:
  std::vector<std::pair<std::string, std::string>> files;
  std::string hex_to_string(const std::string &in)
  {
    std::string output;
    if ((in.length() % 2) != 0)
    {
      throw std::runtime_error("string is not valid length!");
    }
    size_t cnt = in.length() / 2;
    for (size_t i = 0; cnt > i; ++i)
    {
      uint32_t s = 0;
      std::stringstream ss;
      ss << std::hex << in.substr(i * 2, 2);
      ss >> s;
      output.push_back(static_cast<unsigned char>(s));
    }
    return output;
  }
public:
  BinFS() {};
  ~BinFS() {};
  std::string get_file(const std::string &filename)
  {
    auto it = files.begin();
    for (const std::pair<std::string, std::string> &file : files)
    {
      if (file.first == filename)
      {
        return hex_to_string(file.second);
      }
      it++;
    }
    throw std::runtime_error(filename + " not found!");
  }
  void init()
  {
    files.emplace_back("model_emotion.pb","x�ܽm��8ne;%Q��p(����Z�t�����r?�?n�]�=q"	�p�<�y�:�nW+-��z�UWM����z�w�������m��vՒ��=3�~�����J������_�կ�|���-���u?��Ϲf��.�z����'݇wޭp_��V�}��r���{��X����}��z|�ŷ�������������o|[����7��;i�I*�������骟��;Q7�]�����Y�9�S�yU�|j���[�t�Ǿ���|�7����r�w���������$�{������N|��x�5����T��g_��N}�/��t)��=���.���<��W��������=Oyw�O��[�<������_�������w|s՗��V���/��s��ν��Z��;���y����뎽�=�U��o���n��j�~�w����ٯ���ǗS�y�{?|��r�����<W�/�{�\��W�q]Vb�|���=���|��~-�q���J������u����둯^�o�2R�>����ָ��>Lց��iw�����6x��׻p�Q�4��=k��ط���u��[�6�vN��������+��}�q=���6S>�j�ww�J�\��9֚߳�Y��D�y�n�~������U�����<\�������>�4yΛU�'��7�L߅�_o��4�|#q��'����7�?J.��|�;?�۞��_��嫖;~/�L~�Z�Ω?|���N�����}�ߓ�F���?��ן7���y8	�I��� �e���y��͉{������F�R�i��y���X�AO �_Z��O}!_!{�a]f׭��9W�Ή����u�d&��f�9	�QeO}���q����.l߳�W�U��]?׏�l^7s���N�~՛s����\��(�,;G��oyq]��.����H�)�������N��s���gO6�wu��SN�g�}���E�L-�}_oάo,,ϗXE����� �oi���Q���J�^�M�{���|?�$�}<x��J
�Vs9��Sf���5�f�Sn麞���;�ww�C�l5�;<�ʺ��o�kf6�{�V��ѡ�Zwַ^��2ze G�FR<w��T�pb�{���/�B��z�Sвٟ�uG�.?�~A�ޫs[\o�T�Gg���蟽T+���u�\�޹!�{���#;��!�|�{C����m�����\ϓ���g��.+/������?�'z��A�t=���|�����,��x�U=q�a>�<"�賯}X�0N�|W�=z�p��[�a�9[�e���");
  }
};

} // BinFS

#endif // _BINFS_OUTPUT_HPP_

