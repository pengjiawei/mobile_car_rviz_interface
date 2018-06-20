// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: pose.proto

#ifndef PROTOBUF_pose_2eproto_INCLUDED
#define PROTOBUF_pose_2eproto_INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_pose_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsPoseImpl();
void InitDefaultsPose();
inline void InitDefaults() {
  InitDefaultsPose();
}
}  // namespace protobuf_pose_2eproto
class Pose;
class PoseDefaultTypeInternal;
extern PoseDefaultTypeInternal _Pose_default_instance_;
namespace google {
namespace protobuf {
template<> ::Pose* Arena::Create< ::Pose>(Arena*);
}  // namespace protobuf
}  // namespace google

// ===================================================================

class Pose : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Pose) */ {
 public:
  Pose();
  virtual ~Pose();

  Pose(const Pose& from);

  inline Pose& operator=(const Pose& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Pose(Pose&& from) noexcept
    : Pose() {
    *this = ::std::move(from);
  }

  inline Pose& operator=(Pose&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Pose& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Pose* internal_default_instance() {
    return reinterpret_cast<const Pose*>(
               &_Pose_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Pose* other);
  friend void swap(Pose& a, Pose& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Pose* New() const PROTOBUF_FINAL {
    return ::google::protobuf::Arena::Create<Pose>(NULL);
  }

  Pose* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL {
    return ::google::protobuf::Arena::Create<Pose>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Pose& from);
  void MergeFrom(const Pose& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Pose* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 x = 1;
  bool has_x() const;
  void clear_x();
  static const int kXFieldNumber = 1;
  ::google::protobuf::uint32 x() const;
  void set_x(::google::protobuf::uint32 value);

  // required uint32 y = 2;
  bool has_y() const;
  void clear_y();
  static const int kYFieldNumber = 2;
  ::google::protobuf::uint32 y() const;
  void set_y(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:Pose)
 private:
  void set_has_x();
  void clear_has_x();
  void set_has_y();
  void clear_has_y();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::uint32 x_;
  ::google::protobuf::uint32 y_;
  friend struct ::protobuf_pose_2eproto::TableStruct;
  friend void ::protobuf_pose_2eproto::InitDefaultsPoseImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Pose

// required uint32 x = 1;
inline bool Pose::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Pose::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Pose::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Pose::clear_x() {
  x_ = 0u;
  clear_has_x();
}
inline ::google::protobuf::uint32 Pose::x() const {
  // @@protoc_insertion_point(field_get:Pose.x)
  return x_;
}
inline void Pose::set_x(::google::protobuf::uint32 value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:Pose.x)
}

// required uint32 y = 2;
inline bool Pose::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Pose::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Pose::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Pose::clear_y() {
  y_ = 0u;
  clear_has_y();
}
inline ::google::protobuf::uint32 Pose::y() const {
  // @@protoc_insertion_point(field_get:Pose.y)
  return y_;
}
inline void Pose::set_y(::google::protobuf::uint32 value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:Pose.y)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_pose_2eproto_INCLUDED
