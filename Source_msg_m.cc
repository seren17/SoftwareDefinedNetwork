//
// Generated file, do not edit! Created by nedtool 5.4 from Source_msg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "Source_msg_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(Source_msg)

Source_msg::Source_msg(const char *name, short kind) : ::omnetpp::cMessage(name,kind)
{
    this->sourceid = 0;
    this->destid = 0;
    this->networkId = 0;
    this->equipmentId = 0;
    this->interfaceId = 0;
    this->virtualLinkId = 0;
    this->seqNum = 0;
    this->partitionId = 0;
}

Source_msg::Source_msg(const Source_msg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

Source_msg::~Source_msg()
{
}

Source_msg& Source_msg::operator=(const Source_msg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void Source_msg::copy(const Source_msg& other)
{
    this->sourceid = other.sourceid;
    this->destid = other.destid;
    this->networkId = other.networkId;
    this->equipmentId = other.equipmentId;
    this->interfaceId = other.interfaceId;
    this->virtualLinkId = other.virtualLinkId;
    this->seqNum = other.seqNum;
    this->partitionId = other.partitionId;
}

void Source_msg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->sourceid);
    doParsimPacking(b,this->destid);
    doParsimPacking(b,this->networkId);
    doParsimPacking(b,this->equipmentId);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->virtualLinkId);
    doParsimPacking(b,this->seqNum);
    doParsimPacking(b,this->partitionId);
}

void Source_msg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceid);
    doParsimUnpacking(b,this->destid);
    doParsimUnpacking(b,this->networkId);
    doParsimUnpacking(b,this->equipmentId);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->virtualLinkId);
    doParsimUnpacking(b,this->seqNum);
    doParsimUnpacking(b,this->partitionId);
}

int Source_msg::getSourceid() const
{
    return this->sourceid;
}

void Source_msg::setSourceid(int sourceid)
{
    this->sourceid = sourceid;
}

int Source_msg::getDestid() const
{
    return this->destid;
}

void Source_msg::setDestid(int destid)
{
    this->destid = destid;
}

int Source_msg::getNetworkId() const
{
    return this->networkId;
}

void Source_msg::setNetworkId(int networkId)
{
    this->networkId = networkId;
}

int Source_msg::getEquipmentId() const
{
    return this->equipmentId;
}

void Source_msg::setEquipmentId(int equipmentId)
{
    this->equipmentId = equipmentId;
}

int Source_msg::getInterfaceId() const
{
    return this->interfaceId;
}

void Source_msg::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

int Source_msg::getVirtualLinkId() const
{
    return this->virtualLinkId;
}

void Source_msg::setVirtualLinkId(int virtualLinkId)
{
    this->virtualLinkId = virtualLinkId;
}

int Source_msg::getSeqNum() const
{
    return this->seqNum;
}

void Source_msg::setSeqNum(int seqNum)
{
    this->seqNum = seqNum;
}

int Source_msg::getPartitionId() const
{
    return this->partitionId;
}

void Source_msg::setPartitionId(int partitionId)
{
    this->partitionId = partitionId;
}

class Source_msgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Source_msgDescriptor();
    virtual ~Source_msgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Source_msgDescriptor)

Source_msgDescriptor::Source_msgDescriptor() : omnetpp::cClassDescriptor("Source_msg", "omnetpp::cMessage")
{
    propertynames = nullptr;
}

Source_msgDescriptor::~Source_msgDescriptor()
{
    delete[] propertynames;
}

bool Source_msgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Source_msg *>(obj)!=nullptr;
}

const char **Source_msgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Source_msgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Source_msgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int Source_msgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *Source_msgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceid",
        "destid",
        "networkId",
        "equipmentId",
        "interfaceId",
        "virtualLinkId",
        "seqNum",
        "partitionId",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int Source_msgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceid")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destid")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "networkId")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "equipmentId")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+4;
    if (fieldName[0]=='v' && strcmp(fieldName, "virtualLinkId")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqNum")==0) return base+6;
    if (fieldName[0]=='p' && strcmp(fieldName, "partitionId")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Source_msgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **Source_msgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Source_msgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Source_msgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Source_msg *pp = (Source_msg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Source_msgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Source_msg *pp = (Source_msg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Source_msgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Source_msg *pp = (Source_msg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSourceid());
        case 1: return long2string(pp->getDestid());
        case 2: return long2string(pp->getNetworkId());
        case 3: return long2string(pp->getEquipmentId());
        case 4: return long2string(pp->getInterfaceId());
        case 5: return long2string(pp->getVirtualLinkId());
        case 6: return long2string(pp->getSeqNum());
        case 7: return long2string(pp->getPartitionId());
        default: return "";
    }
}

bool Source_msgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Source_msg *pp = (Source_msg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceid(string2long(value)); return true;
        case 1: pp->setDestid(string2long(value)); return true;
        case 2: pp->setNetworkId(string2long(value)); return true;
        case 3: pp->setEquipmentId(string2long(value)); return true;
        case 4: pp->setInterfaceId(string2long(value)); return true;
        case 5: pp->setVirtualLinkId(string2long(value)); return true;
        case 6: pp->setSeqNum(string2long(value)); return true;
        case 7: pp->setPartitionId(string2long(value)); return true;
        default: return false;
    }
}

const char *Source_msgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Source_msgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Source_msg *pp = (Source_msg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


