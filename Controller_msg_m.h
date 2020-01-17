//
// Generated file, do not edit! Created by nedtool 5.4 from Controller_msg.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __CONTROLLER_MSG_M_H
#define __CONTROLLER_MSG_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>Controller_msg.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * message Controller_msg
 * {
 *     int komsu_id_no;
 *     int gate_id;
 *     int type = 1;
 *     int kontrol_dizi[8];
 *     int weight_arr[5];
 *     int array_size;
 * }
 * </pre>
 */
class Controller_msg : public ::omnetpp::cMessage
{
  protected:
    int komsu_id_no;
    int gate_id;
    int type;
    int kontrol_dizi[8];
    int weight_arr[5];
    int array_size;

  private:
    void copy(const Controller_msg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Controller_msg&);

  public:
    Controller_msg(const char *name=nullptr, short kind=0);
    Controller_msg(const Controller_msg& other);
    virtual ~Controller_msg();
    Controller_msg& operator=(const Controller_msg& other);
    virtual Controller_msg *dup() const override {return new Controller_msg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getKomsu_id_no() const;
    virtual void setKomsu_id_no(int komsu_id_no);
    virtual int getGate_id() const;
    virtual void setGate_id(int gate_id);
    virtual int getType() const;
    virtual void setType(int type);
    virtual unsigned int getKontrol_diziArraySize() const;
    virtual int getKontrol_dizi(unsigned int k) const;
    virtual void setKontrol_dizi(unsigned int k, int kontrol_dizi);
    virtual unsigned int getWeight_arrArraySize() const;
    virtual int getWeight_arr(unsigned int k) const;
    virtual void setWeight_arr(unsigned int k, int weight_arr);
    virtual int getArray_size() const;
    virtual void setArray_size(int array_size);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Controller_msg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Controller_msg& obj) {obj.parsimUnpack(b);}


#endif // ifndef __CONTROLLER_MSG_M_H
