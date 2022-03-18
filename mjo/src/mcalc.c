/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mcalc.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "mutf8.h"

extern void
  mjo_u8_calc(int *const o_legal,
              size_t *const o_octets,
              unsigned char const i_octet)
{
  /* generated by util/mjo_utf8_tabgen */
  static struct mjo_utf8_table
  {
    size_t m_size;
    int m_legal;
  } l_table[256] = {
    { 1, 1 }, /*000:0x00:00000000:size=1:valid=y */
    { 1, 1 }, /*001:0x01:00000001:size=1:valid=y */
    { 1, 1 }, /*002:0x02:00000010:size=1:valid=y */
    { 1, 1 }, /*003:0x03:00000011:size=1:valid=y */
    { 1, 1 }, /*004:0x04:00000100:size=1:valid=y */
    { 1, 1 }, /*005:0x05:00000101:size=1:valid=y */
    { 1, 1 }, /*006:0x06:00000110:size=1:valid=y */
    { 1, 1 }, /*007:0x07:00000111:size=1:valid=y */
    { 1, 1 }, /*008:0x08:00001000:size=1:valid=y */
    { 1, 1 }, /*009:0x09:00001001:size=1:valid=y */
    { 1, 1 }, /*010:0x0A:00001010:size=1:valid=y */
    { 1, 1 }, /*011:0x0B:00001011:size=1:valid=y */
    { 1, 1 }, /*012:0x0C:00001100:size=1:valid=y */
    { 1, 1 }, /*013:0x0D:00001101:size=1:valid=y */
    { 1, 1 }, /*014:0x0E:00001110:size=1:valid=y */
    { 1, 1 }, /*015:0x0F:00001111:size=1:valid=y */
    { 1, 1 }, /*016:0x10:00010000:size=1:valid=y */
    { 1, 1 }, /*017:0x11:00010001:size=1:valid=y */
    { 1, 1 }, /*018:0x12:00010010:size=1:valid=y */
    { 1, 1 }, /*019:0x13:00010011:size=1:valid=y */
    { 1, 1 }, /*020:0x14:00010100:size=1:valid=y */
    { 1, 1 }, /*021:0x15:00010101:size=1:valid=y */
    { 1, 1 }, /*022:0x16:00010110:size=1:valid=y */
    { 1, 1 }, /*023:0x17:00010111:size=1:valid=y */
    { 1, 1 }, /*024:0x18:00011000:size=1:valid=y */
    { 1, 1 }, /*025:0x19:00011001:size=1:valid=y */
    { 1, 1 }, /*026:0x1A:00011010:size=1:valid=y */
    { 1, 1 }, /*027:0x1B:00011011:size=1:valid=y */
    { 1, 1 }, /*028:0x1C:00011100:size=1:valid=y */
    { 1, 1 }, /*029:0x1D:00011101:size=1:valid=y */
    { 1, 1 }, /*030:0x1E:00011110:size=1:valid=y */
    { 1, 1 }, /*031:0x1F:00011111:size=1:valid=y */
    { 1, 1 }, /*032:0x20:00100000:size=1:valid=y */
    { 1, 1 }, /*033:0x21:00100001:size=1:valid=y */
    { 1, 1 }, /*034:0x22:00100010:size=1:valid=y */
    { 1, 1 }, /*035:0x23:00100011:size=1:valid=y */
    { 1, 1 }, /*036:0x24:00100100:size=1:valid=y */
    { 1, 1 }, /*037:0x25:00100101:size=1:valid=y */
    { 1, 1 }, /*038:0x26:00100110:size=1:valid=y */
    { 1, 1 }, /*039:0x27:00100111:size=1:valid=y */
    { 1, 1 }, /*040:0x28:00101000:size=1:valid=y */
    { 1, 1 }, /*041:0x29:00101001:size=1:valid=y */
    { 1, 1 }, /*042:0x2A:00101010:size=1:valid=y */
    { 1, 1 }, /*043:0x2B:00101011:size=1:valid=y */
    { 1, 1 }, /*044:0x2C:00101100:size=1:valid=y */
    { 1, 1 }, /*045:0x2D:00101101:size=1:valid=y */
    { 1, 1 }, /*046:0x2E:00101110:size=1:valid=y */
    { 1, 1 }, /*047:0x2F:00101111:size=1:valid=y */
    { 1, 1 }, /*048:0x30:00110000:size=1:valid=y */
    { 1, 1 }, /*049:0x31:00110001:size=1:valid=y */
    { 1, 1 }, /*050:0x32:00110010:size=1:valid=y */
    { 1, 1 }, /*051:0x33:00110011:size=1:valid=y */
    { 1, 1 }, /*052:0x34:00110100:size=1:valid=y */
    { 1, 1 }, /*053:0x35:00110101:size=1:valid=y */
    { 1, 1 }, /*054:0x36:00110110:size=1:valid=y */
    { 1, 1 }, /*055:0x37:00110111:size=1:valid=y */
    { 1, 1 }, /*056:0x38:00111000:size=1:valid=y */
    { 1, 1 }, /*057:0x39:00111001:size=1:valid=y */
    { 1, 1 }, /*058:0x3A:00111010:size=1:valid=y */
    { 1, 1 }, /*059:0x3B:00111011:size=1:valid=y */
    { 1, 1 }, /*060:0x3C:00111100:size=1:valid=y */
    { 1, 1 }, /*061:0x3D:00111101:size=1:valid=y */
    { 1, 1 }, /*062:0x3E:00111110:size=1:valid=y */
    { 1, 1 }, /*063:0x3F:00111111:size=1:valid=y */
    { 1, 1 }, /*064:0x40:01000000:size=1:valid=y */
    { 1, 1 }, /*065:0x41:01000001:size=1:valid=y */
    { 1, 1 }, /*066:0x42:01000010:size=1:valid=y */
    { 1, 1 }, /*067:0x43:01000011:size=1:valid=y */
    { 1, 1 }, /*068:0x44:01000100:size=1:valid=y */
    { 1, 1 }, /*069:0x45:01000101:size=1:valid=y */
    { 1, 1 }, /*070:0x46:01000110:size=1:valid=y */
    { 1, 1 }, /*071:0x47:01000111:size=1:valid=y */
    { 1, 1 }, /*072:0x48:01001000:size=1:valid=y */
    { 1, 1 }, /*073:0x49:01001001:size=1:valid=y */
    { 1, 1 }, /*074:0x4A:01001010:size=1:valid=y */
    { 1, 1 }, /*075:0x4B:01001011:size=1:valid=y */
    { 1, 1 }, /*076:0x4C:01001100:size=1:valid=y */
    { 1, 1 }, /*077:0x4D:01001101:size=1:valid=y */
    { 1, 1 }, /*078:0x4E:01001110:size=1:valid=y */
    { 1, 1 }, /*079:0x4F:01001111:size=1:valid=y */
    { 1, 1 }, /*080:0x50:01010000:size=1:valid=y */
    { 1, 1 }, /*081:0x51:01010001:size=1:valid=y */
    { 1, 1 }, /*082:0x52:01010010:size=1:valid=y */
    { 1, 1 }, /*083:0x53:01010011:size=1:valid=y */
    { 1, 1 }, /*084:0x54:01010100:size=1:valid=y */
    { 1, 1 }, /*085:0x55:01010101:size=1:valid=y */
    { 1, 1 }, /*086:0x56:01010110:size=1:valid=y */
    { 1, 1 }, /*087:0x57:01010111:size=1:valid=y */
    { 1, 1 }, /*088:0x58:01011000:size=1:valid=y */
    { 1, 1 }, /*089:0x59:01011001:size=1:valid=y */
    { 1, 1 }, /*090:0x5A:01011010:size=1:valid=y */
    { 1, 1 }, /*091:0x5B:01011011:size=1:valid=y */
    { 1, 1 }, /*092:0x5C:01011100:size=1:valid=y */
    { 1, 1 }, /*093:0x5D:01011101:size=1:valid=y */
    { 1, 1 }, /*094:0x5E:01011110:size=1:valid=y */
    { 1, 1 }, /*095:0x5F:01011111:size=1:valid=y */
    { 1, 1 }, /*096:0x60:01100000:size=1:valid=y */
    { 1, 1 }, /*097:0x61:01100001:size=1:valid=y */
    { 1, 1 }, /*098:0x62:01100010:size=1:valid=y */
    { 1, 1 }, /*099:0x63:01100011:size=1:valid=y */
    { 1, 1 }, /*100:0x64:01100100:size=1:valid=y */
    { 1, 1 }, /*101:0x65:01100101:size=1:valid=y */
    { 1, 1 }, /*102:0x66:01100110:size=1:valid=y */
    { 1, 1 }, /*103:0x67:01100111:size=1:valid=y */
    { 1, 1 }, /*104:0x68:01101000:size=1:valid=y */
    { 1, 1 }, /*105:0x69:01101001:size=1:valid=y */
    { 1, 1 }, /*106:0x6A:01101010:size=1:valid=y */
    { 1, 1 }, /*107:0x6B:01101011:size=1:valid=y */
    { 1, 1 }, /*108:0x6C:01101100:size=1:valid=y */
    { 1, 1 }, /*109:0x6D:01101101:size=1:valid=y */
    { 1, 1 }, /*110:0x6E:01101110:size=1:valid=y */
    { 1, 1 }, /*111:0x6F:01101111:size=1:valid=y */
    { 1, 1 }, /*112:0x70:01110000:size=1:valid=y */
    { 1, 1 }, /*113:0x71:01110001:size=1:valid=y */
    { 1, 1 }, /*114:0x72:01110010:size=1:valid=y */
    { 1, 1 }, /*115:0x73:01110011:size=1:valid=y */
    { 1, 1 }, /*116:0x74:01110100:size=1:valid=y */
    { 1, 1 }, /*117:0x75:01110101:size=1:valid=y */
    { 1, 1 }, /*118:0x76:01110110:size=1:valid=y */
    { 1, 1 }, /*119:0x77:01110111:size=1:valid=y */
    { 1, 1 }, /*120:0x78:01111000:size=1:valid=y */
    { 1, 1 }, /*121:0x79:01111001:size=1:valid=y */
    { 1, 1 }, /*122:0x7A:01111010:size=1:valid=y */
    { 1, 1 }, /*123:0x7B:01111011:size=1:valid=y */
    { 1, 1 }, /*124:0x7C:01111100:size=1:valid=y */
    { 1, 1 }, /*125:0x7D:01111101:size=1:valid=y */
    { 1, 1 }, /*126:0x7E:01111110:size=1:valid=y */
    { 1, 1 }, /*127:0x7F:01111111:size=1:valid=y */
    { 1, 0 }, /*128:0x80:10000000:size=1:valid=n */
    { 1, 0 }, /*129:0x81:10000001:size=1:valid=n */
    { 1, 0 }, /*130:0x82:10000010:size=1:valid=n */
    { 1, 0 }, /*131:0x83:10000011:size=1:valid=n */
    { 1, 0 }, /*132:0x84:10000100:size=1:valid=n */
    { 1, 0 }, /*133:0x85:10000101:size=1:valid=n */
    { 1, 0 }, /*134:0x86:10000110:size=1:valid=n */
    { 1, 0 }, /*135:0x87:10000111:size=1:valid=n */
    { 1, 0 }, /*136:0x88:10001000:size=1:valid=n */
    { 1, 0 }, /*137:0x89:10001001:size=1:valid=n */
    { 1, 0 }, /*138:0x8A:10001010:size=1:valid=n */
    { 1, 0 }, /*139:0x8B:10001011:size=1:valid=n */
    { 1, 0 }, /*140:0x8C:10001100:size=1:valid=n */
    { 1, 0 }, /*141:0x8D:10001101:size=1:valid=n */
    { 1, 0 }, /*142:0x8E:10001110:size=1:valid=n */
    { 1, 0 }, /*143:0x8F:10001111:size=1:valid=n */
    { 1, 0 }, /*144:0x90:10010000:size=1:valid=n */
    { 1, 0 }, /*145:0x91:10010001:size=1:valid=n */
    { 1, 0 }, /*146:0x92:10010010:size=1:valid=n */
    { 1, 0 }, /*147:0x93:10010011:size=1:valid=n */
    { 1, 0 }, /*148:0x94:10010100:size=1:valid=n */
    { 1, 0 }, /*149:0x95:10010101:size=1:valid=n */
    { 1, 0 }, /*150:0x96:10010110:size=1:valid=n */
    { 1, 0 }, /*151:0x97:10010111:size=1:valid=n */
    { 1, 0 }, /*152:0x98:10011000:size=1:valid=n */
    { 1, 0 }, /*153:0x99:10011001:size=1:valid=n */
    { 1, 0 }, /*154:0x9A:10011010:size=1:valid=n */
    { 1, 0 }, /*155:0x9B:10011011:size=1:valid=n */
    { 1, 0 }, /*156:0x9C:10011100:size=1:valid=n */
    { 1, 0 }, /*157:0x9D:10011101:size=1:valid=n */
    { 1, 0 }, /*158:0x9E:10011110:size=1:valid=n */
    { 1, 0 }, /*159:0x9F:10011111:size=1:valid=n */
    { 1, 0 }, /*160:0xA0:10100000:size=1:valid=n */
    { 1, 0 }, /*161:0xA1:10100001:size=1:valid=n */
    { 1, 0 }, /*162:0xA2:10100010:size=1:valid=n */
    { 1, 0 }, /*163:0xA3:10100011:size=1:valid=n */
    { 1, 0 }, /*164:0xA4:10100100:size=1:valid=n */
    { 1, 0 }, /*165:0xA5:10100101:size=1:valid=n */
    { 1, 0 }, /*166:0xA6:10100110:size=1:valid=n */
    { 1, 0 }, /*167:0xA7:10100111:size=1:valid=n */
    { 1, 0 }, /*168:0xA8:10101000:size=1:valid=n */
    { 1, 0 }, /*169:0xA9:10101001:size=1:valid=n */
    { 1, 0 }, /*170:0xAA:10101010:size=1:valid=n */
    { 1, 0 }, /*171:0xAB:10101011:size=1:valid=n */
    { 1, 0 }, /*172:0xAC:10101100:size=1:valid=n */
    { 1, 0 }, /*173:0xAD:10101101:size=1:valid=n */
    { 1, 0 }, /*174:0xAE:10101110:size=1:valid=n */
    { 1, 0 }, /*175:0xAF:10101111:size=1:valid=n */
    { 1, 0 }, /*176:0xB0:10110000:size=1:valid=n */
    { 1, 0 }, /*177:0xB1:10110001:size=1:valid=n */
    { 1, 0 }, /*178:0xB2:10110010:size=1:valid=n */
    { 1, 0 }, /*179:0xB3:10110011:size=1:valid=n */
    { 1, 0 }, /*180:0xB4:10110100:size=1:valid=n */
    { 1, 0 }, /*181:0xB5:10110101:size=1:valid=n */
    { 1, 0 }, /*182:0xB6:10110110:size=1:valid=n */
    { 1, 0 }, /*183:0xB7:10110111:size=1:valid=n */
    { 1, 0 }, /*184:0xB8:10111000:size=1:valid=n */
    { 1, 0 }, /*185:0xB9:10111001:size=1:valid=n */
    { 1, 0 }, /*186:0xBA:10111010:size=1:valid=n */
    { 1, 0 }, /*187:0xBB:10111011:size=1:valid=n */
    { 1, 0 }, /*188:0xBC:10111100:size=1:valid=n */
    { 1, 0 }, /*189:0xBD:10111101:size=1:valid=n */
    { 1, 0 }, /*190:0xBE:10111110:size=1:valid=n */
    { 1, 0 }, /*191:0xBF:10111111:size=1:valid=n */
    { 2, 1 }, /*192:0xC0:11000000:size=2:valid=y */
    { 2, 1 }, /*193:0xC1:11000001:size=2:valid=y */
    { 2, 1 }, /*194:0xC2:11000010:size=2:valid=y */
    { 2, 1 }, /*195:0xC3:11000011:size=2:valid=y */
    { 2, 1 }, /*196:0xC4:11000100:size=2:valid=y */
    { 2, 1 }, /*197:0xC5:11000101:size=2:valid=y */
    { 2, 1 }, /*198:0xC6:11000110:size=2:valid=y */
    { 2, 1 }, /*199:0xC7:11000111:size=2:valid=y */
    { 2, 1 }, /*200:0xC8:11001000:size=2:valid=y */
    { 2, 1 }, /*201:0xC9:11001001:size=2:valid=y */
    { 2, 1 }, /*202:0xCA:11001010:size=2:valid=y */
    { 2, 1 }, /*203:0xCB:11001011:size=2:valid=y */
    { 2, 1 }, /*204:0xCC:11001100:size=2:valid=y */
    { 2, 1 }, /*205:0xCD:11001101:size=2:valid=y */
    { 2, 1 }, /*206:0xCE:11001110:size=2:valid=y */
    { 2, 1 }, /*207:0xCF:11001111:size=2:valid=y */
    { 2, 1 }, /*208:0xD0:11010000:size=2:valid=y */
    { 2, 1 }, /*209:0xD1:11010001:size=2:valid=y */
    { 2, 1 }, /*210:0xD2:11010010:size=2:valid=y */
    { 2, 1 }, /*211:0xD3:11010011:size=2:valid=y */
    { 2, 1 }, /*212:0xD4:11010100:size=2:valid=y */
    { 2, 1 }, /*213:0xD5:11010101:size=2:valid=y */
    { 2, 1 }, /*214:0xD6:11010110:size=2:valid=y */
    { 2, 1 }, /*215:0xD7:11010111:size=2:valid=y */
    { 2, 1 }, /*216:0xD8:11011000:size=2:valid=y */
    { 2, 1 }, /*217:0xD9:11011001:size=2:valid=y */
    { 2, 1 }, /*218:0xDA:11011010:size=2:valid=y */
    { 2, 1 }, /*219:0xDB:11011011:size=2:valid=y */
    { 2, 1 }, /*220:0xDC:11011100:size=2:valid=y */
    { 2, 1 }, /*221:0xDD:11011101:size=2:valid=y */
    { 2, 1 }, /*222:0xDE:11011110:size=2:valid=y */
    { 2, 1 }, /*223:0xDF:11011111:size=2:valid=y */
    { 3, 1 }, /*224:0xE0:11100000:size=3:valid=y */
    { 3, 1 }, /*225:0xE1:11100001:size=3:valid=y */
    { 3, 1 }, /*226:0xE2:11100010:size=3:valid=y */
    { 3, 1 }, /*227:0xE3:11100011:size=3:valid=y */
    { 3, 1 }, /*228:0xE4:11100100:size=3:valid=y */
    { 3, 1 }, /*229:0xE5:11100101:size=3:valid=y */
    { 3, 1 }, /*230:0xE6:11100110:size=3:valid=y */
    { 3, 1 }, /*231:0xE7:11100111:size=3:valid=y */
    { 3, 1 }, /*232:0xE8:11101000:size=3:valid=y */
    { 3, 1 }, /*233:0xE9:11101001:size=3:valid=y */
    { 3, 1 }, /*234:0xEA:11101010:size=3:valid=y */
    { 3, 1 }, /*235:0xEB:11101011:size=3:valid=y */
    { 3, 1 }, /*236:0xEC:11101100:size=3:valid=y */
    { 3, 1 }, /*237:0xED:11101101:size=3:valid=y */
    { 3, 1 }, /*238:0xEE:11101110:size=3:valid=y */
    { 3, 1 }, /*239:0xEF:11101111:size=3:valid=y */
    { 4, 1 }, /*240:0xF0:11110000:size=4:valid=y */
    { 4, 1 }, /*241:0xF1:11110001:size=4:valid=y */
    { 4, 1 }, /*242:0xF2:11110010:size=4:valid=y */
    { 4, 1 }, /*243:0xF3:11110011:size=4:valid=y */
    { 4, 1 }, /*244:0xF4:11110100:size=4:valid=y */
    { 4, 1 }, /*245:0xF5:11110101:size=4:valid=y */
    { 4, 1 }, /*246:0xF6:11110110:size=4:valid=y */
    { 4, 1 }, /*247:0xF7:11110111:size=4:valid=y */
    { 5, 1 }, /*248:0xF8:11111000:size=5:valid=y */
    { 5, 1 }, /*249:0xF9:11111001:size=5:valid=y */
    { 5, 1 }, /*250:0xFA:11111010:size=5:valid=y */
    { 5, 1 }, /*251:0xFB:11111011:size=5:valid=y */
    { 6, 1 }, /*252:0xFC:11111100:size=6:valid=y */
    { 6, 1 }, /*253:0xFD:11111101:size=6:valid=y */
    { 1, 0 }, /*254:0xFE:11111110:size=1:valid=n */
    { 1, 0 }  /*255:0xFF:11111111:size=1:valid=n */
  };          /*l_table */
  struct mjo_utf8_table const *l_ent;

  l_ent = &l_table[i_octet];

  if (o_octets)
    {
      (*o_octets) = l_ent->m_size;
    }

  if (o_legal)
    {
      *o_legal = l_ent->m_legal;
    }

  return;
}