#ifndef __MEXPORTDIRNOTIFYACK_H
#define __MEXPORTDIRNOTIFYACK_H

#include "msg/Message.h"
#include <string>
using namespace std;

class MExportDirNotifyAck : public Message {
  inodeno_t ino;

 public:
  inodeno_t get_ino() { return ino; }
  
  MExportDirNotifyAck() {}
  MExportDirNotifyAck(inodeno_t ino) :
	Message(MSG_MDS_EXPORTDIRNOTIFYACK) {
	this->ino = ino;
  }
  virtual char *get_type_name() { return "ExNotA"; }

  virtual void decode_payload(crope& s, int& off) {
	s.copy(off, sizeof(ino), (char*)&ino);
	off += sizeof(ino);
  }
  
  virtual void encode_payload(crope& s) {
	s.append((char*)&ino, sizeof(ino));
  }
  
};

#endif
