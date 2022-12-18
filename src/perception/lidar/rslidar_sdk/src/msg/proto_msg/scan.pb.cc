// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: scan.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "scan.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace proto_msg {

namespace {

const ::google::protobuf::Descriptor* LidarScan_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  LidarScan_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_scan_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_scan_2eproto() {
  protobuf_AddDesc_scan_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "scan.proto");
  GOOGLE_CHECK(file != NULL);
  LidarScan_descriptor_ = file->message_type(0);
  static const int LidarScan_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LidarScan, timestamp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LidarScan, seq_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LidarScan, data_),
  };
  LidarScan_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      LidarScan_descriptor_,
      LidarScan::default_instance_,
      LidarScan_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LidarScan, _has_bits_[0]),
      -1,
      -1,
      sizeof(LidarScan),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LidarScan, _internal_metadata_),
      -1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_scan_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      LidarScan_descriptor_, &LidarScan::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_scan_2eproto() {
  delete LidarScan::default_instance_;
  delete LidarScan_reflection_;
}

void protobuf_AddDesc_scan_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_scan_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\nscan.proto\022\tproto_msg\"9\n\tLidarScan\022\021\n\t"
    "timestamp\030\001 \001(\001\022\013\n\003seq\030\002 \001(\r\022\014\n\004data\030\003 \003"
    "(\014", 82);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "scan.proto", &protobuf_RegisterTypes);
  LidarScan::default_instance_ = new LidarScan();
  LidarScan::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_scan_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_scan_2eproto {
  StaticDescriptorInitializer_scan_2eproto() {
    protobuf_AddDesc_scan_2eproto();
  }
} static_descriptor_initializer_scan_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int LidarScan::kTimestampFieldNumber;
const int LidarScan::kSeqFieldNumber;
const int LidarScan::kDataFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

LidarScan::LidarScan()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:proto_msg.LidarScan)
}

void LidarScan::InitAsDefaultInstance() {
}

LidarScan::LidarScan(const LidarScan& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:proto_msg.LidarScan)
}

void LidarScan::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  timestamp_ = 0;
  seq_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

LidarScan::~LidarScan() {
  // @@protoc_insertion_point(destructor:proto_msg.LidarScan)
  SharedDtor();
}

void LidarScan::SharedDtor() {
  if (this != default_instance_) {
  }
}

void LidarScan::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* LidarScan::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LidarScan_descriptor_;
}

const LidarScan& LidarScan::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_scan_2eproto();
  return *default_instance_;
}

LidarScan* LidarScan::default_instance_ = NULL;

LidarScan* LidarScan::New(::google::protobuf::Arena* arena) const {
  LidarScan* n = new LidarScan;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void LidarScan::Clear() {
// @@protoc_insertion_point(message_clear_start:proto_msg.LidarScan)
  if (_has_bits_[0 / 32] & 3u) {
    timestamp_ = 0;
    seq_ = 0u;
  }
  data_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  if (_internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->Clear();
  }
}

bool LidarScan::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:proto_msg.LidarScan)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional double timestamp = 1;
      case 1: {
        if (tag == 9) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &timestamp_)));
          set_has_timestamp();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_seq;
        break;
      }

      // optional uint32 seq = 2;
      case 2: {
        if (tag == 16) {
         parse_seq:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &seq_)));
          set_has_seq();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_data;
        break;
      }

      // repeated bytes data = 3;
      case 3: {
        if (tag == 26) {
         parse_data:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->add_data()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_data;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:proto_msg.LidarScan)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:proto_msg.LidarScan)
  return false;
#undef DO_
}

void LidarScan::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:proto_msg.LidarScan)
  // optional double timestamp = 1;
  if (has_timestamp()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(1, this->timestamp(), output);
  }

  // optional uint32 seq = 2;
  if (has_seq()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->seq(), output);
  }

  // repeated bytes data = 3;
  for (int i = 0; i < this->data_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      3, this->data(i), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:proto_msg.LidarScan)
}

::google::protobuf::uint8* LidarScan::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto_msg.LidarScan)
  // optional double timestamp = 1;
  if (has_timestamp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, this->timestamp(), target);
  }

  // optional uint32 seq = 2;
  if (has_seq()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->seq(), target);
  }

  // repeated bytes data = 3;
  for (int i = 0; i < this->data_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteBytesToArray(3, this->data(i), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto_msg.LidarScan)
  return target;
}

int LidarScan::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:proto_msg.LidarScan)
  int total_size = 0;

  if (_has_bits_[0 / 32] & 3u) {
    // optional double timestamp = 1;
    if (has_timestamp()) {
      total_size += 1 + 8;
    }

    // optional uint32 seq = 2;
    if (has_seq()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->seq());
    }

  }
  // repeated bytes data = 3;
  total_size += 1 * this->data_size();
  for (int i = 0; i < this->data_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::BytesSize(
      this->data(i));
  }

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void LidarScan::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:proto_msg.LidarScan)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const LidarScan* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const LidarScan>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:proto_msg.LidarScan)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:proto_msg.LidarScan)
    MergeFrom(*source);
  }
}

void LidarScan::MergeFrom(const LidarScan& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:proto_msg.LidarScan)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  data_.MergeFrom(from.data_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_timestamp()) {
      set_timestamp(from.timestamp());
    }
    if (from.has_seq()) {
      set_seq(from.seq());
    }
  }
  if (from._internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->MergeFrom(from.unknown_fields());
  }
}

void LidarScan::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:proto_msg.LidarScan)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LidarScan::CopyFrom(const LidarScan& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto_msg.LidarScan)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LidarScan::IsInitialized() const {

  return true;
}

void LidarScan::Swap(LidarScan* other) {
  if (other == this) return;
  InternalSwap(other);
}
void LidarScan::InternalSwap(LidarScan* other) {
  std::swap(timestamp_, other->timestamp_);
  std::swap(seq_, other->seq_);
  data_.UnsafeArenaSwap(&other->data_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata LidarScan::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = LidarScan_descriptor_;
  metadata.reflection = LidarScan_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// LidarScan

// optional double timestamp = 1;
bool LidarScan::has_timestamp() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void LidarScan::set_has_timestamp() {
  _has_bits_[0] |= 0x00000001u;
}
void LidarScan::clear_has_timestamp() {
  _has_bits_[0] &= ~0x00000001u;
}
void LidarScan::clear_timestamp() {
  timestamp_ = 0;
  clear_has_timestamp();
}
 double LidarScan::timestamp() const {
  // @@protoc_insertion_point(field_get:proto_msg.LidarScan.timestamp)
  return timestamp_;
}
 void LidarScan::set_timestamp(double value) {
  set_has_timestamp();
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:proto_msg.LidarScan.timestamp)
}

// optional uint32 seq = 2;
bool LidarScan::has_seq() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void LidarScan::set_has_seq() {
  _has_bits_[0] |= 0x00000002u;
}
void LidarScan::clear_has_seq() {
  _has_bits_[0] &= ~0x00000002u;
}
void LidarScan::clear_seq() {
  seq_ = 0u;
  clear_has_seq();
}
 ::google::protobuf::uint32 LidarScan::seq() const {
  // @@protoc_insertion_point(field_get:proto_msg.LidarScan.seq)
  return seq_;
}
 void LidarScan::set_seq(::google::protobuf::uint32 value) {
  set_has_seq();
  seq_ = value;
  // @@protoc_insertion_point(field_set:proto_msg.LidarScan.seq)
}

// repeated bytes data = 3;
int LidarScan::data_size() const {
  return data_.size();
}
void LidarScan::clear_data() {
  data_.Clear();
}
 const ::std::string& LidarScan::data(int index) const {
  // @@protoc_insertion_point(field_get:proto_msg.LidarScan.data)
  return data_.Get(index);
}
 ::std::string* LidarScan::mutable_data(int index) {
  // @@protoc_insertion_point(field_mutable:proto_msg.LidarScan.data)
  return data_.Mutable(index);
}
 void LidarScan::set_data(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:proto_msg.LidarScan.data)
  data_.Mutable(index)->assign(value);
}
 void LidarScan::set_data(int index, const char* value) {
  data_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:proto_msg.LidarScan.data)
}
 void LidarScan::set_data(int index, const void* value, size_t size) {
  data_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:proto_msg.LidarScan.data)
}
 ::std::string* LidarScan::add_data() {
  // @@protoc_insertion_point(field_add_mutable:proto_msg.LidarScan.data)
  return data_.Add();
}
 void LidarScan::add_data(const ::std::string& value) {
  data_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:proto_msg.LidarScan.data)
}
 void LidarScan::add_data(const char* value) {
  data_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:proto_msg.LidarScan.data)
}
 void LidarScan::add_data(const void* value, size_t size) {
  data_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:proto_msg.LidarScan.data)
}
 const ::google::protobuf::RepeatedPtrField< ::std::string>&
LidarScan::data() const {
  // @@protoc_insertion_point(field_list:proto_msg.LidarScan.data)
  return data_;
}
 ::google::protobuf::RepeatedPtrField< ::std::string>*
LidarScan::mutable_data() {
  // @@protoc_insertion_point(field_mutable_list:proto_msg.LidarScan.data)
  return &data_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_msg

// @@protoc_insertion_point(global_scope)
