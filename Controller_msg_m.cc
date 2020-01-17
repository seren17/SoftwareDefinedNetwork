//
// Generated file, do not edit! Created by nedtool 5.4 from Controller_msg.msg.
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
#include "Controller_msg_m.h"

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

Register_Class(Controller_msg)

Controller_msg::Controller_msg(const char *name, short kind) : ::omnetpp::cMessage(name,kind)
{
    this->komsu_id_no = 0;
    this->gate_id = 0;
    this->type = 1;
    for (unsigned int i=0; i<8; i++)
        this->kontrol_dizi[i] = 0;
    for (unsigned int i=0; i<5; i++)
        this->weight_arr[i] = 0;
    this->array_size = 0;
}

Controller_msg::Controller_msg(const Controller_msg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

Controller_msg::~Controller_msg()
{
}

Controller_msg& Controller_msg::operator=(const Controller_msg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void Controller_msg::copy(const Controller_msg& other)
{
    this->komsu_id_no = other.komsu_id_no;
    this->gate_id = other.gate_id;
    this->type = other.type;
    for (unsigned int i=0; i<8; i++)
        this->kontrol_dizi[i] = other.kontrol_dizi[i];
    for (unsigned int i=0; i<5; i++)
        this->weight_arr[i] = other.weight_arr[i];
    this->array_size = other.array_size;
}

void Controller_msg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->komsu_id_no);
    doParsimPacking(b,this->gate_id);
    doParsimPacking(b,this->type);
    doParsimArrayPacking(b,this->kontrol_dizi,8);
    doParsimArrayPacking(b,this->weight_arr,5);
    doParsimPacking(b,this->array_size);
}

void Controller_msg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->komsu_id_no);
    doParsimUnpacking(b,this->gate_id);
    doParsimUnpacking(b,this->type);
    doParsimArrayUnpacking(b,this->kontrol_dizi,8);
    doParsimArrayUnpacking(b,this->weight_arr,5);
    doParsimUnpacking(b,this->array_size);
}

int Controller_msg::getKomsu_id_no() const
{
    return this->komsu_id_no;
}

void Controller_msg::setKomsu_id_no(int komsu_id_no)
{
    this->komsu_id_no = komsu_id_no;
}

int Controller_msg::getGate_id() const
{
    return this->gate_id;
}

void Controller_msg::setGate_id(int gate_id)
{
    this->gate_id = gate_id;
}

int Controller_msg::getType() const
{
    return this->type;
}

void Controller_msg::setType(int type)
{
    this->type = type;
}

unsigned int Controller_msg::getKontrol_diziArraySize() const
{
    return 8;
}

int Controller_msg::getKontrol_dizi(unsigned int k) const
{
    if (k>=8) throw omnetpp::cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    return this->kontrol_dizi[k];
}

void Controller_msg::setKontrol_dizi(unsigned int k, int kontrol_dizi)
{
    if (k>=8) throw omnetpp::cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    this->kontrol_dizi[k] = kontrol_dizi;
}

unsigned int Controller_msg::getWeight_arrArraySize() const
{
    return 5;
}

int Controller_msg::getWeight_arr(unsigned int k) const
{
    if (k>=5) throw omnetpp::cRuntimeError("Array of size 5 indexed by %lu", (unsigned long)k);
    return this->weight_arr[k];
}

void Controller_msg::setWeight_arr(unsigned int k, int weight_arr)
{
    if (k>=5) throw omnetpp::cRuntimeError("Array of size 5 indexed by %lu", (unsigned long)k);
    this->weight_arr[k] = weight_arr;
}

int Controller_msg::getArray_size() const
{
    return this->array_size;
}

void Controller_msg::setArray_size(int array_size)
{
    this->array_size = array_size;
}

class Controller_msgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Controller_msgDescriptor();
    virtual ~Controller_msgDescriptor();

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

Register_ClassDescriptor(Controller_msgDescriptor)

Controller_msgDescriptor::Controller_msgDescriptor() : omnetpp::cClassDescriptor("Controller_msg", "omnetpp::cMessage")
{
    propertynames = nullptr;
}

Controller_msgDescriptor::~Controller_msgDescriptor()
{
    delete[] propertynames;
}

bool Controller_msgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Controller_msg *>(obj)!=nullptr;
}

const char **Controller_msgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Controller_msgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Controller_msgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int Controller_msgDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *Controller_msgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "komsu_id_no",
        "gate_id",
        "type",
        "kontrol_dizi",
        "weight_arr",
        "array_size",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int Controller_msgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='k' && strcmp(fieldName, "komsu_id_no")==0) return base+0;
    if (fieldName[0]=='g' && strcmp(fieldName, "gate_id")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+2;
    if (fieldName[0]=='k' && strcmp(fieldName, "kontrol_dizi")==0) return base+3;
    if (fieldName[0]=='w' && strcmp(fieldName, "weight_arr")==0) return base+4;
    if (fieldName[0]=='a' && strcmp(fieldName, "array_size")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Controller_msgDescriptor::getFieldTypeString(int field) const
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
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **Controller_msgDescriptor::getFieldPropertyNames(int field) const
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

const char *Controller_msgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Controller_msgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Controller_msg *pp = (Controller_msg *)object; (void)pp;
    switch (field) {
        case 3: return 8;
        case 4: return 5;
        default: return 0;
    }
}

const char *Controller_msgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Controller_msg *pp = (Controller_msg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Controller_msgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Controller_msg *pp = (Controller_msg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getKomsu_id_no());
        case 1: return long2string(pp->getGate_id());
        case 2: return long2string(pp->getType());
        case 3: return long2string(pp->getKontrol_dizi(i));
        case 4: return long2string(pp->getWeight_arr(i));
        case 5: return long2string(pp->getArray_size());
        default: return "";
    }
}

bool Controller_msgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Controller_msg *pp = (Controller_msg *)object; (void)pp;
    switch (field) {
        case 0: pp->setKomsu_id_no(string2long(value)); return true;
        case 1: pp->setGate_id(string2long(value)); return true;
        case 2: pp->setType(string2long(value)); return true;
        case 3: pp->setKontrol_dizi(i,string2long(value)); return true;
        case 4: pp->setWeight_arr(i,string2long(value)); return true;
        case 5: pp->setArray_size(string2long(value)); return true;
        default: return false;
    }
}

const char *Controller_msgDescriptor::getFieldStructName(int field) const
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

void *Controller_msgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Controller_msg *pp = (Controller_msg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


