//
// Generated file, do not edit! Created by nedtool 5.4 from Sorgu.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __SORGU_M_H
#define __SORGU_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>Sorgu.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * message Sorgu
 * {
 *     int kaynakid;
 *     int hedefid;
 *     int gateindex;
 *     bool faildetect = false;
 * 
 * 
 * 
 * }
 * </pre>
 */
class Sorgu : public ::omnetpp::cMessage
{
  protected:
    int kaynakid;
    int hedefid;
    int gateindex;
    bool faildetect;

  private:
    void copy(const Sorgu& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Sorgu&);

  public:
    Sorgu(const char *name=nullptr, short kind=0);
    Sorgu(const Sorgu& other);
    virtual ~Sorgu();
    Sorgu& operator=(const Sorgu& other);
    virtual Sorgu *dup() const override {return new Sorgu(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getKaynakid() const;
    virtual void setKaynakid(int kaynakid);
    virtual int getHedefid() const;
    virtual void setHedefid(int hedefid);
    virtual int getGateindex() const;
    virtual void setGateindex(int gateindex);
    virtual bool getFaildetect() const;
    virtual void setFaildetect(bool faildetect);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Sorgu& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Sorgu& obj) {obj.parsimUnpack(b);}


#endif // ifndef __SORGU_M_H
